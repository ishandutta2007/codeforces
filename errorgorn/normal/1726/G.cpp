//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());


struct node1{
	int s,e,m;
	int val=0;
	node1 *l,*r;
	
	node1 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node1(s,m);
			r=new node1(m+1,e);
		}
	}
	
	void update(int i,int k){
		val+=k;
		
		if (s==e) return;
		if (i<=m) l->update(i,k);
		else r->update(i,k);
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root1=new node1(0,600005);

const int INF=1e18;

struct node2{
	int s,e,m;
	ii val;
	int lazy=0;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		val={0,-s};
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void propo(){
		if (lazy==0) return;
		val.fi+=lazy;
		if (s!=e){
			l->lazy+=lazy;
			r->lazy+=lazy;
		}
		lazy=0;
	}
	
	void update(int i,int j,int k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
		
			l->propo(),r->propo();
			val=min(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		propo();
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
} *root2;

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n;
vector<ii> arr;
bool proc[400005];

void rage(){
	cout<<0<<endl;
	exit(0);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n;
	arr.resize(n);
	rep(x,0,n) cin>>arr[x].fi;
	rep(x,0,n) cin>>arr[x].se;
	
	sort(all(arr));
	
	if (arr.front().fi==arr.back().fi){
		cout<<fac[n]<<endl;
		return 0;
	}
	
	int lim=INF;
	rep(x,0,n) if (arr[x].se==1) lim=min(lim,arr[x].fi);
	
	if (lim==INF) rage();
	
	lim+=n-1;
	
	//cout<<lim<<endl;
	
	if (lim<arr.back().fi) rage();
	
	map<ii,int> occ;
	for (auto it:arr) occ[it]++;
	
	int ans=1;
	for (auto [a,b]:occ){
		ans=ans*fac[b]%MOD;
		if (a.se==1){
			if (a.fi==lim) ans=ans*nCk(n,b)%MOD;
			else if (b>1) rage();
			else proc[a.fi]=true;
		}
	}
	
	for (auto it:arr) root1->update(it.fi,1);
	root2=new node2(0,lim-1);
	rep(x,0,lim) root2->update(x,x,lim-x-root1->query(x+1,lim));
	
	while (root2->val.fi<0){
		int temp=-root2->val.se;
		if (proc[temp]) rage();
		root2->update(temp,temp,INF);
	}
	
	vector<int> v;
	for (auto it:arr) if (it.se==0) v.pub(it.fi);
	reverse(all(v));
	
	//for (auto it:v) cout<<it<<" "; cout<<endl;
	
	while (true){
		auto temp=root2->query(0,lim-1);
		bool can=(!v.empty() && v.back()+root1->query(0,v.back()-1)==lim);
		
		int pos=-temp.se;
		
		if (temp.fi==0 && can){
			if (pos>=v.back()){
				if (proc[pos]){
					root1->update(pos,-1);
					root2->update(pos,lim-1,-1);
					proc[pos]=false;
				}
				root2->update(pos,pos,INF);
			}
			else{
				root1->update(v.back(),-1);
				if (v.back()<lim) root2->update(v.back(),lim-1,-1);
				v.pob();
			}
		}
		else if (temp.fi==0){
			if (proc[pos]){
				root1->update(pos,-1);
				root2->update(pos,lim-1,-1);
				proc[pos]=false;
			}
			root2->update(pos,pos,INF);
		}
		else if (can){
			root1->update(v.back(),-1);
			if (v.back()<lim) root2->update(v.back(),lim-1,-1);
			v.pob();
		}
		else{
			break;
		}
	}
	
	rep(x,0,lim) if (proc[x]) rage();
	if (!v.empty()) rage();
	
	cout<<ans<<endl;
}