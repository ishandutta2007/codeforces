#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
bool cmp(const P&a,const P&b){
	double x = atan2((double)(a.sc),(double)(a.fi));
	double y = atan2((double)(b.sc),(double)(b.fi));
	if(abs(x-y)<1e-12) return false;
	return x < y;
}
bool cmp_eq(const P&a,const P&b){
	return (cmp(a,b) == false && cmp(b,a) == false);
}
int n;
vector<P>ply[100005],vec[100005];
vector<P>za;
int beg[100005],en[100005],prer=-1;
vector<int>val;
vector<int>pre;
map<int,int>M;
int q;
vector<P>query[300005];

vector<int>add[300005];
int ans[100005];

struct seg{
	int seg[(1<<20)];
	void update(int p,int a){p+=(1<<19)-1;seg[p]+=a;while(p){p=(p-1)/2;seg[p]=seg[p*2+1]+seg[p*2+2];}}
	int query(int a,int b,int k,int l,int r){
		if(r<a||b<l)return 0;
		if(a<=l&&r<=b)return seg[k];
		return query(a,b,k*2+1,l,(l+r)/2)+query(a,b,k*2+2,(l+r)/2+1,r);
	}
}kaede;

int main(){
	scanf("%d",&n);
	rep(i,n){
		int x; scanf("%d",&x);
		rep(j,x){
			int a,b; scanf("%d%d",&a,&b);
			ply[i].pb(mp(a,b));
		}
		rep(j,x){
			P p = mp(ply[i][(j+1)%x].fi-ply[i][j].fi,ply[i][(j+1)%x].sc-ply[i][j].sc);
			vec[i].pb(p);
			za.pb(p);
		}
	}
	sort(za.begin(),za.end(),cmp);
	//cerr << za.size() << endl;
		//rep(i,za.size()) cerr << za[i].fi << " " << za[i].sc << endl;
	za.erase(unique(za.begin(),za.end(),cmp_eq),za.end());
	//cerr << za.size() << endl;
	rep(i,n){
		beg[i] = prer+1;
		en[i] = prer+vec[i].size();
		prer += vec[i].size();
		rep(j,vec[i].size()){
			int d = lower_bound(za.begin(),za.end(),vec[i][j],cmp)-za.begin();
			//cerr << d << " " << za[d].fi << " " << za[d].sc << " " << vec[i][j].fi << " " << vec[i][j].sc << " " << cmp_eq(za[d],vec[i][j]) << endl;
			assert(d<za.size() && cmp_eq(za[d],vec[i][j]));
			val.pb(d);
		}
	}
	//cerr << prer << endl;
	rep(i,val.size()){
		int V = val[i];
		if(M.find(V) == M.end()){
			pre.pb(-1);
			kaede.update(i,1);
		}
		else{
			pre.pb(M[V]);
			add[M[V]].pb(i);
		}
		M[V] = i;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		int x,y; scanf("%d%d",&x,&y); x--; y--;
		x = beg[x];
		y = en[y];
		query[x].pb(mp(y,i));
	}
	for(int i=0;i<300005;i++){
		for(int j=0;j<query[i].size();j++){
			P rng = mp(i,query[i][j].fi);
			int id = query[i][j].sc;
			ans[id] = kaede.query(rng.fi,rng.sc,0,0,(1<<19)-1);
		}
		for(int j=0;j<add[i].size();j++){
			kaede.update(add[i][j],1);
		}
	}
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
	//assert(0);
}