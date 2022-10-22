#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define M 100005
#define N 1035

typedef long long ll;
const int Mod=(int)1e9+7;

ll Fast(ll x,int b) {
	ll tmp=1;
	for(;b;b>>=1,x=x*x%Mod) if(b&1) tmp=tmp*x%Mod;
	return tmp;
}
ll Fac[M],Inv[M];
ll C(int x,int y) {
	if(x<y) return 0;
	return Fac[x]*Inv[y]%Mod*Inv[x-y]%Mod;
}

map<int,int> Id;
int id_cnt;
int cnt[M];

bool judge(int x) {
	for(;x;x/=10) if(x%10!=4 && x%10!=7) return false;
	return true;
}
ll dp[N][N];
int main() {
	Fac[0]=1;
	FOR(i,1,100000) Fac[i]=Fac[i-1]*i%Mod;
	Inv[100000]=Fast(Fac[100000],Mod-2);
	DOR(i,100000,1) Inv[i-1]=Inv[i]*i%Mod;
	
	int n,K,x,tot=0;
	scanf("%d%d",&n,&K);
	FOR(i,1,n) {
		scanf("%d",&x);
		if(!judge(x)) tot++;
		else {
			if(!Id[x]) Id[x]=++id_cnt;
			cnt[Id[x]]++;
		}
	}
	dp[0][0]=1;
	FOR(i,1,id_cnt) {
		FOR(j,0,i-1) {
			dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*cnt[i])%Mod;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%Mod;
		}
	}
	ll res=0;
	FOR(i,0,min(K,id_cnt)) res=(res+dp[id_cnt][i]*C(tot,K-i))%Mod;
	printf("%lld\n",res);
	return 0;
}