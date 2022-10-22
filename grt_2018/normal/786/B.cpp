#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 100*1000+10;
const ll INF = (ll)1e18;
int n,m,s;

struct Node {
	ll g,f;
	int id;
	bool active;
};

struct Edge {
	int l1,r1,l2,r2,c;
	bool operator < (const Edge &ee) const {
		return l1<ee.l1;
	}
};

struct SegTree {
	Node T[(1<<18)];
	int R, log2n;
	void init(int x) {
		R=1;
		while(R<=x) {
			R*=2;
			log2n++;
		}
		for(int i=R; i<2*R; i++) {
			T[i].f = T[i].g = INF;
			T[i].id = i-R;
		}
		for(int i=R-1; i>=1; i--) {
			T[i].f = T[i].g = INF;
			T[i].id = T[2*i].id;
		}
	}
	void propagate(int x) {
		if(T[x].active) {
			T[2*x].active = 1;
			T[2*x+1].active = 1;
			return;
		}
		T[2*x].g = min(T[2*x].g,T[x].g);
		T[2*x+1].g=min(T[2*x+1].g,T[x].g);
	}
	void updateTf(int a) {
		while(a>1) {
			a/=2;
			if(T[2*a].active&&T[2*a+1].active) T[a].active = 1;
			else if(T[2*a].active) {
				T[a].f = min(T[2*a+1].f,T[2*a+1].g);
				T[a].id = T[2*a+1].id;
			} else if(T[2*a+1].active) {
				T[a].f = min(T[2*a].f,T[2*a].g);
				T[a].id =T[2*a].id;
			} else {
				if(min(T[2*a].f,T[2*a].g)<=min(T[2*a+1].f,T[2*a+1].g)) {
					T[a].f = min(T[2*a].f,T[2*a].g);
					T[a].id=  T[2*a].id;
				} else {
					T[a].f = min(T[2*a+1].f,T[2*a+1].g);
					T[a].id = T[2*a+1].id;
				}
			}
		}
	}
	void update(int a,int b,ll c,bool f=0) {
		a+=R; b+=R;
		for(int i=log2n; i>0; i--) {
			propagate(a/(1<<i));
			propagate(b/(1<<i));
		}
		if(f) {
			T[a].active = 1;
			T[b].active = 1;
		} else {
			T[a].g = min(T[a].g,c);
			T[b].g = min(T[b].g,c);
		}
		int pa = a, pb = b;
		while(a/2!=b/2) {
			if(a%2==0) {
				if(f) T[a+1].active = 1;
				T[a+1].g = min(T[a+1].g,c);
			}
			if(b%2==1) {
				if(f) T[b-1].active = 1;
				T[b-1].g = min(T[b-1].g,c);
			}
			a/=2; b/=2;
		}
		updateTf(pa); updateTf(pb);
	}
	pair<ll,int> query(int a,int b) {
		a+=R; b+=R;
		for(int i=log2n; i>0; i--) {
			propagate(a/(1<<i));
			propagate(b/(1<<i));
		}
		updateTf(a); updateTf(b);
		pair<ll,int> w = {INF,0};
		if(a>b) return w;
		if(!T[a].active) w = {T[a].g,T[a].id};
		if(!T[b].active&&w.ST>T[b].g) w = {T[b].g,T[b].id};
		while(a/2!=b/2) {
			if(a%2==0&&!T[a+1].active) {
				if(w.ST>min(T[a+1].g,T[a+1].f)) w = {min(T[a+1].g,T[a+1].f),T[a+1].id};
			}
			if(b%2==1&&!T[b-1].active) {
				if(w.ST>min(T[b-1].f,T[b-1].g)) w = {min(T[b-1].f,T[b-1].g),T[b-1].id};
			}
			a/=2; b/=2;
		}
		return w;
	}
} distanc, seg;
Edge e[nax];
ll dd[nax];

void coutTree() {
	for(int i=1; i<distanc.R*2; i++) {
		cout<<i<<" : "<<distanc.T[i].f<<" "<<distanc.T[i].g<<" "<<distanc.T[i].active<<"\n";
	}
}

int main() {_
	cin>>n>>m>>s;
	for(int t,l1,l2,r1,r2,c, i=0; i<m ; i++) {
		cin>>t;
		if(t==1) {
			cin>>l1>>l2>>c;
			r1 = l1; r2 = l2;
		} else if(t==2) {
			cin>>l1>>l2>>r2>>c;
			r1 = l1;
		} else {
			cin>>l2>>l1>>r1>>c;
			r2 = l2;
		}
		e[i] = {l1,r1,l2,r2,c};
	}
	for(int i=1; i<=n; i++) dd[i] = INF;
	dd[s] = 0;
	sort(e,e+m);
	seg.init(m);
	for(int i=0; i<m; i++) {
		seg.update(i,i,-e[i].r1);
	}
	distanc.init(n);
	distanc.update(s,s,0);
	pair<ll,int>toop = distanc.query(1,n);
	while(toop.ST!=INF) {
		int x = toop.ND;
		if(distanc.T[x+distanc.R].active) {
			break;
		}
		distanc.update(x,x,INF,1);
		//if(dd[x]==toop.ST) {
		int l=0,r=m-1,mid=-1;
		while(l<=r) {
			mid = (l+r)/2;
			if(e[mid].l1<=x) {
				l = mid+1;
			} else r = mid-1;
		}
		l--;
		//cout<<x<<" "<<l<<"\n";
		pair<ll,int>edg = seg.query(0,l);
		//cout<<edg.ST<<" "<<edg.ND<<"\n";
		while(-edg.ST>=(ll)x) {
			distanc.update(e[edg.ND].l2,e[edg.ND].r2,toop.ST+e[edg.ND].c);
			seg.update(edg.ND,edg.ND,INF,1);
			edg = seg.query(0,l);
			//cout<<edg.ST<<" "<<edg.ND<<"\n";
		}
		dd[x] = min(dd[x],toop.ST);
		//}
		toop = distanc.query(1,n);
		//coutTree();
		//cout<<toop.ST<<" "<<toop.ND<<"\n";
	}
	for(int i=1; i<=n; i++) {
		if(dd[i]==INF) cout<<"-1 ";
		else cout<<dd[i]<<" ";
	}
	
}