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
#define N 300010
#define M 10000010
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll n,tot,ans,s[9],v[9][840];
void dfs(int x,ll nw,ll ls){
	v[x][(n-nw)%840]=nw;ans=max(ans,nw);
	if(x<1)return;
	ll r=min((n-nw)/x,s[x]);
	nw+=r*x;ls-=s[x]*x;
	for(;~(r--);nw-=x){
		if(nw+ls<=ans||v[x-1][(n-nw)%840]>=nw)return;
		dfs(x-1,nw,ls);
	}
}
int main(){
	scanf("%lld",&n);
	rep(i,1,8){
		scanf("%lld",&s[i]);tot+=s[i]*i;
	}
	if(tot<=n)return printf("%lld\n",tot),0;
	rep(i,0,8)rep(j,0,839)v[i][j]=-1;
	dfs(8,0,tot);printf("%lld\n",ans);
}