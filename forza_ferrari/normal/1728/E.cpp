#include <bits/stdc++.h>
using namespace std;
#define For(Ti,Ta,Tb) for(int Ti=(Ta);Ti<=(Tb);++Ti)
#define Dec(Ti,Ta,Tb) for(int Ti=(Ta);Ti>=(Tb);--Ti)
#define Debug(...) fprintf(stderr,__VA_ARGS__)
using ll=long long;
void ExGCD(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return;}
	ll t;ExGCD(b,a%b,t,x);
	y=t-a/b*x;
}
const int N=6e5+5,SqrtN=560;
pair<ll,ll> Solve(ll a,ll b,ll c){
	ll g=gcd(a,b),x,y;
	if(c%g) return {-1,0};
	ExGCD(a,b,x,y),x*=c/g,y*=c/g;
	ll p=b/g;x=(x%p+p)%p;
	if(c-a*x<0) return {-1,0};
	return {x,p};
}
int n,dif[N];ll f[N],mx[N],ans[N];
vector<pair<ll,int>> qry[SqrtN];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	ll s=0;
	For(i,1,n){
		int x,y;cin>>x>>y;
		s+=y,dif[i]=x-y;
	}
	sort(dif+1,dif+n+1,greater<int>());
	For(i,0,n) s+=dif[i],f[i]=s;
	int m;cin>>m;
	For(_,1,m){
		int a,b;cin>>a>>b;
		auto [x,d]=Solve(a,b,n);
		if(x==-1){ans[_]=-1;continue;}
		x*=a,d*=a;
		if(d>=SqrtN) for(ll i=x;i<=n;i+=d) ans[_]=max(ans[_],f[i]);
		else qry[d].emplace_back(x,_);
	}
	For(d,1,SqrtN-1){
		For(i,0,n) mx[i]=0;
		sort(qry[d].begin(),qry[d].end(),greater<pair<ll,int>>());
		auto it=qry[d].begin();
		Dec(i,n,0){
			mx[i]=max(f[i],i+d<=n?mx[i+d]:0);
			while(it!=qry[d].end()&&it->first==i){
				ans[it->second]=mx[i],++it;
			}
		}
	}
	For(i,1,m) cout<<ans[i]<<'\n';
	#ifdef zyz
		Debug("Elapsed time: %dms\n",int(clock()));
	#endif
	return 0;
}