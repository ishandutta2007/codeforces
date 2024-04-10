#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 100005

typedef long long ll;
const int Mod=(int)1e9+7;

ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y) {return x*y/gcd(x,y);}

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}

int sum[M];
//ll dp[M];
vector<int> G[M];
int main() {
	int n,x,mx=0;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&x);
		sum[x]++;
		if(mx<x) mx=x;
	}
	FOR(i,1,mx) sum[i]+=sum[i-1];
	FOR(i,1,mx) {
		for(int j=i;j<=mx;j+=i) G[j].push_back(i);
		G[i].push_back(mx+1);
	}
	ll res=0;
	FOR(i,1,mx) {
		sort(G[i].begin(),G[i].end());
		int len=G[i].size();
		ll tmp=1,s=1;
		FOR(j,1,len-1) {
			s=s*Fast(min(j,len-2),sum[G[i][j]-1]-sum[G[i][j-1]-1])%Mod;
			tmp=tmp*Fast(j,sum[G[i][j]-1]-sum[G[i][j-1]-1])%Mod;
		}
		res=(res+tmp-s)%Mod;
	}
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}