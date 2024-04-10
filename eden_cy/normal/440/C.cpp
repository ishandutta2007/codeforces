#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define INF 0x3f3f3f3f
#define M 17

typedef long long ll;

ll H[M];
int solve(ll x,int k) {
	if(!x) return 0;
	if(!k) return INF;
	return min(solve(x%H[k],k-1)+x/H[k]*k,solve(H[k]-x%H[k],k-1)+x/H[k]*k+k);
}
int main() {
	ll n;
	scanf("%lld",&n);
	FOR(i,1,16) H[i]=(H[i-1]<<3)+(H[i-1]<<1)|1;
	printf("%d\n",solve(n,16));
	return 0;
}