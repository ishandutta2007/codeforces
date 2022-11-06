#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=1e7;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
vector<int>p[N+1];
int main(){
	ll ans=Inf;int n,s1,s2;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);p[x].pb(i);
	}
	rep(i,1,N){ll x=0,y=0;int sx,sy;
		rep(j,1,N/i)if(!p[i*j].empty()){
			if(x){
				y=j;sy=p[i*j][0];break;	
			}else if(p[i*j].size()>1){
				x=y=j;sx=p[i*j][0];sy=p[i*j][1];break;
			}else x=j,sx=p[i*j][0];
		}
		if(y&&x*y*i<ans){
			if(sx>sy)swap(sx,sy);
			ans=x*y*i;s1=sx;s2=sy;
		}
	}
	printf("%d %d\n",s1,s2);
}