// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct UFDS{
	int p[200005];
	
	UFDS(){
		rep(x,0,200005) p[x]=x;
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	void unions(int i,int j){
		i=par(i),j=par(j);
		p[i]=j;
	}
} ufds;

int n,q;

ii qu[50005];

struct R{
	ll l,r;
	int t;
	int idx;
};

vector<R> v;
vector<int> ans;

vector<ii> edges[50005];

void build(vector<R> v){
	if (sz(v)==1) return;
	
	vector<R> vl,vr;
	ll m=(v.back().r+1)>>1;
	
	for (auto [l,r,t,idx]:v){
		if (r<m) vl.pub({l,r,t,idx});
		else if (m<=l) vr.pub({l-m,r-m,t,idx});
		else vl.pub({l,m-1,t,idx}),vr.pub({0,r-m,t,idx});
	}
	
	int idx0=0,idx1=0;
	
	while (idx0<sz(vl)){
		edges[min(vl[idx0].t,vr[idx1].t)].pub({vl[idx0].idx,vr[idx1].idx});
		// if (min(vl[idx0].t,vr[idx1].t)==q-1){
			// cout<<vl[idx0].l<<" "<<vl[idx0].r<<" "<<vl[idx0].idx<<endl;
			// cout<<vr[idx1].l<<" "<<vr[idx1].r<<" "<<vr[idx1].idx<<endl;
			// cout<<endl;
		// }
		
		if (vl[idx0].r==vr[idx1].r) idx0++,idx1++;
		else if (vl[idx0].r<vr[idx1].r) idx0++;
		else idx1++;
	}
	
	build(vl);
	build(vr);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	
	ll a,b;
	string c;
	
	memset(qu,-1,sizeof(qu));
	
	rep(x,0,q){
		cin>>c;
		cin>>a>>b;
		
		if (c=="ask") qu[x]={a,b};
		else v.pub({a,b,x,0});
	}
	
	sort(all(v),[](R i,R j){
		return i.l<j.l;
	});
	
	int sz=sz(v);
	if (v.empty()) v={ {0,(1LL<<n)-1,q-1,0} };
	else{
		if (v[0].l!=0) v.pub({0,v[0].l-1,q-1,0});
		if (v[sz-1].r!=(1LL<<n)-1) v.pub({v[sz-1].r+1,(1LL<<n)-1,q-1,0});
		rep(x,0,sz-1) if (v[x].r+1!=v[x+1].l) v.pub({v[x].r+1,v[x+1].l-1,q-1,0});
	}
	
	int IDX=0;
	vector<R> temp;
	for (auto [l,r,t,idx]:v){
		if (l==r) temp.pub({l,r,t,IDX++});
		else{
			int val=1LL<<(63-__builtin_clzll(l^r));
			
			int m=r&(~(val-1));
			temp.pub({l,m-1,t,IDX++});
			temp.pub({m,r,t,IDX++});
		}
	}
	
	v=temp;
	sort(all(v),[](R i,R j){
		return i.l<j.l;
	});
	
	// for (auto [l,r,t,idx]:v){
		// cout<<l<<" "<<r<<" "<<t<<" "<<idx<<endl;
	// }
	
	build(v);
	
	//for (auto [a,b]:edges[q-1]) cout<<a<<"_"<<b<<" "; cout<<endl;
	
	rep(x,q,0){
		for (auto [a,b]:edges[x]) ufds.unions(a,b);
		
		if (qu[x]!=ii(-1,-1)){
			ll l=qu[x].fi,r=qu[x].se;
			
			int lo=-1,hi=sz(v)-1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				if (l<=v[mi].r) hi=mi;
				else lo=mi;
			}
			l=v[hi].idx;
			
			lo=-1,hi=sz(v)-1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				if (r<=v[mi].r) hi=mi;
				else lo=mi;
			}
			r=v[hi].idx;
			
			ans.pub(ufds.par(l)==ufds.par(r));
		}
	}
	
	reverse(all(ans));
	for (auto it:ans) cout<<it<<endl;
}