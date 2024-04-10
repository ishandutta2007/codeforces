#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 1000005
#define N 200005

typedef long long ll;
const int Mod=(int)1e9+7;

int gcd(int x,int y) {return y?gcd(y,x%y):x;}

ll H[N];
ll sum[M];
int cnt[M];
int main() {
	int n,x,mx=0;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d",&x);
		if(mx<x) mx=x;
		cnt[x]++;
	}
	H[0]=1;
	FOR(i,1,n) H[i]=H[i-1]*2%Mod;
	ll res=0;
	DOR(i,mx,2) {
		for(int j=i;j<=mx;j+=i) sum[i]+=cnt[j];
		if(!sum[i]) continue;
		sum[i]=sum[i]*H[sum[i]-1]%Mod;
		for(int j=i+i;j<=mx;j+=i) sum[i]=(sum[i]-sum[j])%Mod;
		res=(res+sum[i]*i)%Mod;
	}
	printf("%lld\n",(res+Mod)%Mod);
	return 0;
}