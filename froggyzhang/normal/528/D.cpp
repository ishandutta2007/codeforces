#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 800080
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll mod=998244353;
const ll G=3;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int tr[N],n,m,k,ans,lim;
char s[N],t[N];
ll p[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
const ll invG=qpow(G,mod-2);
void NTT(ll *f,int flag,int n){
	for(int i=0;i<n;++i){
		if(i<tr[i])swap(f[i],f[tr[i]]);
	}
	for(int p=2;p<=n;p<<=1){
		int len=(p>>1);
		ll wn=qpow(flag?G:invG,(mod-1)/p);
		for(int k=0;k<n;k+=p){
			ll buf=1;
			for(int i=k;i<k+len;++i){
				ll tmp=f[i+len]*buf%mod;
				f[i+len]=(f[i]-tmp+mod)%mod;
				f[i]=(f[i]+tmp)%mod;
				buf=buf*wn%mod;
			}
		}
	}
	if(!flag){
		ll invn=qpow(n,mod-2);
		for(int i=0;i<n;++i){
			f[i]=f[i]*invn%mod;
		}
	}
}
void Solve(char c){
	static ll f[N],g[N];
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	int las=-inf;
	for(int i=0;i<n;++i){
		if(s[i]==c){
			f[i]=1;las=i;continue;
		}
		if(i-las<=k){
			f[i]=1;
		}
	}
	las=inf;
	for(int i=n-1;i>=0;--i){
		if(s[i]==c){
			las=i;continue;
		}
		if(las-i<=k)f[i]=1;
	}
	for(int i=0;i<m;++i){
		if(t[i]==c)g[i]=1;
	}
	NTT(f,1,lim),NTT(g,1,lim);
	for(int i=0;i<lim;++i){
		p[i]=(p[i]+f[i]*g[i])%mod;
	}
}
int main(){
	n=read(),m=read(),k=read();
	scanf("%s%s",s,t);
	reverse(t,t+m);
	lim=1;
	while(lim<(n+m))lim<<=1;
	for(int i=0;i<lim;++i){
		tr[i]=((tr[i>>1]>>1)|((i&1)?lim>>1:0));
	} 
	Solve('A'),Solve('G'),Solve('C'),Solve('T');
	NTT(p,0,lim);
	for(int i=m-1;i<n;++i){
		if(p[i]==m){
			++ans;
		}
	}
	printf("%d\n",ans);
	return 0;
}