#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=2e5+1,mod=998244353,INF=0x3f3f3f3f;
int T;
ll n,x,ans;
ll solve1(ll x){
	ll out=0,now=0;
	FOR(i,0,63){
		if(i&1)x-=1ll<<i-1,now|=1ll<<i-1;
		if(x<0)return out;
		if((~x>>i&1)^(i&1))out|=1ll<<i;
	}
}
ll solve2(ll x){
	ll out=0,now=0,d=1;
	FOR(i,0,63){
		if(i&1){
			if(x<d<<1){
				if(x<d)out|=1ll<<i;
			}
			else if(!(x-(d<<1)>>i&1))
				out|=1ll<<i;
		}
		else{
			if(i)x-=1ll<<i-2,d=1ll<<i;
			if(x<0)return out;
			if(x>=d&&x-d>>i+1&1)
				out|=1ll<<i;
		}
	}
}
int main(){
	for(scanf("%d",&T);T--;){
		cin>>n,x=(n-1)/3,ans=0;
		if(n%3!=1)ans^=solve2(x);
		if(n%3!=2)ans^=solve1(x);
		cout<<ans<<'\n';
	}
	return 0;
}