#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int hea[maxn],nxt[maxn],to[maxn],w[maxn],P[maxn],inv[maxn];
int siz[maxn],dep[maxn],U[maxn],D[maxn],son[maxn],tot,n,mod,ans;
map<int,int>up,down;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int phi(int x) {
	int t=x;
	for(int i=2;i*i<=x;i++) {
		if(x%i==0)t=t/i*(i-1);
		while(x%i==0)x/=i;
	}
	if(x!=1)t=t/x*(x-1);
	return t;
}
void ins(int a,int b,int c) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
	w[tot]=c;
}
void pre(int x,int fa) {
	siz[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa) {
			dep[to[i]]=dep[x]+1;
			D[to[i]]=(D[x]*10+w[i])%mod;
			U[to[i]]=(U[x]+w[i]*P[dep[x]])%mod;
			pre(to[i],x);
			siz[x]+=siz[to[i]];
			if(siz[to[i]]>siz[son[x]])
				son[x]=to[i];
		}
}
void calc(int x,int p) {
	ans+=up[(1ll*D[p]*P[dep[p]]%mod-1ll*D[x]*P[2*dep[p]]%mod*inv[dep[x]]%mod+U[p]+mod)%mod];
	ans+=down[(1ll*D[p]*inv[dep[p]]%mod+1ll*(U[p]-U[x])*inv[2*dep[p]]%mod+mod)%mod];
}
void calc(int x,int fa,int p) {
	calc(x,p);
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa)calc(to[i],x,p);
}
void add(int x) {
	up[U[x]]++;
	down[1ll*D[x]*inv[dep[x]]%mod]++;
}
void add(int x,int fa) {
	add(x);
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa)add(to[i],x);
}
void dfs(int x,int fa) {
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa&&to[i]!=son[x]) {
			dfs(to[i],x);
			down.clear();
			up.clear();
		}
	if(son[x])dfs(son[x],x);
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa&&to[i]!=son[x]) {
			calc(to[i],x,x);
			add(to[i],x);
		}
	calc(x,x);
	add(x);
}
signed main() {
	int a,b,c;
	scanf("%lld%lld",&n,&mod);
	P[0]=1;
	for(int i=1;i<=2*n;i++)
		P[i]=10ll*P[i-1]%mod;
	inv[2*n]=qpow(P[2*n],phi(mod)-1);
	for(int i=2*n-1;i>=0;i--)
		inv[i]=inv[i+1]*10ll%mod;
	for(int i=1;i<n;i++) {
		scanf("%lld%lld%lld",&a,&b,&c);
		a++,b++;
		ins(a,b,c);
		ins(b,a,c);
	}
	pre(1,0);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}