#include <bits/stdc++.h>

using namespace std;

struct Que {
	int id,l,r;
};

#define ST first
#define ND second

const int MAXN = 500001;
const long long INF = (long long)1000*1000*1000*1000*1000*1000;
int n,q;
vector<pair<int,int> >V[MAXN];
vector<Que>queries[MAXN];
long long tf[(1<<21)];
long long tg[(1<<21)];
long long ans[MAXN];
int R,log2n;

void propagate(int x) {
	tg[2*x]+=tg[x];
	tg[2*x+1]+=tg[x];
	tg[x]=0; 
}

void updateTf(int a) {
	//tf[a] = 0;
	while(a>1) {
		a/=2;
		tf[a] = min(tf[2*a]+tg[2*a],tf[2*a+1]+tg[2*a+1]);
	}
}

void update(int a,int b,long long c) {
	a+=R; b+=R;
	for(int i=log2n; i>0; i--) {
		propagate((int)a/(1<<i));
		propagate((int)b/(1<<i));
	}
	int pa=a,pb=b;
	tg[a]+=c; if(a!=b) tg[b]+=c;
	while(a/2!=b/2) {
		if(a%2==0) tg[a+1]+=c;
		if(b%2==1) tg[b-1]+=c;
		a/=2; b/=2;
	}
	updateTf(pa); updateTf(pb);
}

long long query(int a,int b) {
	a+=R; b+=R;
	for(int i=log2n; i>0; i--) {
		propagate((int)a/(1<<i));
		propagate((int)b/(1<<i));
	}
	updateTf(a); updateTf(b);
	long long w = min(tf[a]+tg[a],tf[b]+tg[b]); 
	while(a/2!=b/2) {
		if(a%2==0) w = min(w,tf[a+1]+tg[a+1]);
		if(b%2==1) w=min(w,tf[b-1]+tg[b-1]);
		a/=2; b/=2;
	}
	return w;
}

long long d=0;
bool visited[MAXN];
int end_interval[MAXN];
int maksi;

void dfs_init(int x) {
	visited[x]=1;
	maksi = max(maksi,x);
	for(auto nbh:V[x]) {
		if(!visited[nbh.ST]) {
			d+=nbh.ND;
			dfs_init(nbh.ST);
			d-=nbh.ND;
		}
	}
	if(V[x].size()==1) {
		update(x,x,d);
	}
	end_interval[x] = maksi;
}

void dfs(int x) {
	visited[x]=1;
	for(auto it:queries[x]) {
		ans[it.id] = query(it.l,it.r);
	}
	for(auto nbh:V[x]) {
		if(!visited[nbh.ST]) {
			update(1,n,nbh.ND);
			update(nbh.ST,end_interval[nbh.ST],-2*nbh.ND);
			//for(int i=1; i<=n;i++) {
				//cout<<"("<<query(i,i)<<","<<tf[i+R]<<","<<tg[i+R]<<") ";
			//}
			//cout<<"\n";
			dfs(nbh.ST);
			update(1,n,-nbh.ND);
			update(nbh.ST,end_interval[nbh.ST],2*nbh.ND);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(int p,w,i=2; i<=n;i++) {
		cin>>p>>w;
		V[i].push_back({p,w});
		V[p].push_back({i,w});
	}
	for(int l,r,v,i = 0; i<q;i++) {
		cin>>v>>l>>r;
		queries[v].push_back({i,l,r});
	}
	R = pow(2,(int)log2(n)+2); log2n = log2(R);
	dfs_init(1);
	for(int i=1; i<=n;i++) {
		if(V[i].size()!=1) update(i,i,INF);
	}
	//cout<<query(2,2)<<"\n";
	for(int i=1; i<=n;i++) visited[i]=0;
	dfs(1);
	for(int i=0; i<q;i++) cout<<ans[i]<<"\n";
	return 0;
}