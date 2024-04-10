#include <bits/stdc++.h>
#define maxn 1200005
typedef long long ll;
const int mod = 998244353;
const int g = 3;
int rev[maxn],n,m,A[maxn],B[maxn],C[maxn],P[maxn],F[maxn],G[maxn],H[maxn],Prx[maxn],
p[29],w[29],sum;
char S[maxn],R[maxn];

int sqr(int x){return (ll)x*x%mod;}

int qpow(int a,int b){
	if(b==0)return 1;
	ll d=qpow(a,b>>1);d=d*d%mod;
	if(b&1)d=d*a%mod;
	return d;
}

void NTT (int *a, int lim, int flag) {
	for (int i=1;i<lim;++i) rev[i] = (rev[i>>1]>>1) | ((lim>>1) * (i&1));
	for (int i=1;i<lim;++i) if (i<rev[i]) std::swap(a[i],a[rev[i]]);
	for (int i=1;i<lim;i<<=1) {
		int wn = qpow(g,(mod-1)/(i<<1));
		if (flag == -1) wn = qpow(wn,mod-2);
		for (int j=0;j<lim;j+=(i<<1)) {
			for (int k=0,w=1;k<i;++k,w=(ll)w*wn%mod) {
				int a1 = a[j+k], a2 = (ll) w * a[j+k+i] % mod;
				a[j+k] = (a1 + a2) % mod;
				a[j+k+i] = (a1 - a2 + mod) % mod;
			}
		}
	}if (flag == -1)
		for (int i=0,inv=qpow(lim,mod-2);i<lim;++i) a[i] = (ll) a[i] * inv % mod;
}

void conv(int len){
	std::memset ( C, 0, sizeof (C));
	int lim = 1; while (lim <= len + 2) lim <<= 1;
	NTT(A,lim,1); NTT(B,lim,1);
	for (int i = 0; i < lim; ++ i) C[i] = (ll) A[i] * B[i] % mod;
	NTT(C,lim,-1);
	std::memset( A, 0, sizeof(A));
	std::memset( B, 0, sizeof(B));
}

int main(){
	for(int i=1;i<=26;++i)scanf("%d",&p[i]);
	scanf("%s%s",R+1,S+1);
	n = std::strlen(S+1); m = std::strlen(R+1);
	std::reverse(R+1,R+m+1);
	for (int i = 1; i <= 26; ++ i) 
		w[i] = (rand() * 32768 + rand())%mod;
	for (int i = 1; i <= n; ++ i) {
		F[i] = w[S[i] - 'a' + 1];
		Prx[i] = (Prx[i-1] + (ll) F[i] * F[i] % mod) % mod;
	} for (int i = 1; i <= m; ++ i) {
		G[i] = w[p[R[i] - 'a' + 1]];
		H[i] = w[R[i] - 'a' + 1];
		sum = (sum + (ll)H[i] * G[i] % mod) % mod;
	}
	for (int i = 1; i <= m; ++ i) A[i] = (H[i] + G[i]) % mod;
	for (int i = 1; i <= n; ++ i) B[i] = F[i];
	conv(n+m);
	for (int j = 1; j <= n+m; ++j) P[j] = (P[j] - C[j] + mod) % mod;
	for (int j= m+1; j <= n+1; ++j) {
		P[j] = (P[j] + (Prx[j-1] - Prx[j-m-1] + mod) % mod) % mod;
		P[j] = (P[j] + sum) % mod;
	}for (int j = m+1; j <= n+1; ++j)printf("%d",P[j]==0);
	return 0;
}