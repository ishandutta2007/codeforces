#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1000005
#define N 21

typedef long long ll;
const int Mod=(int)1e9+7;

int sum[1<<N];
int cnt[1<<N];
ll H[M];
int main() {
	int n,x;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&x);
		sum[x]++;
	}
	H[0]=1;
	FOR(i,1,n) H[i]=(H[i-1]<<1)%Mod;
	FOR(i,0,20) FOR(j,0,(1<<20)-1) if(!(j&(1<<i))) sum[j]+=sum[j|(1<<i)];
	cnt[0]=0;
	ll res=0;
	FOR(i,0,(1<<20)-1) {
		if(i) cnt[i]=cnt[i^(i&-i)]+1;
		if(cnt[i]&1) res=(res-H[sum[i]]+1)%Mod;
		else res=(res+H[sum[i]]-1)%Mod;
	}
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}