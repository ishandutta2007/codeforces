#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 400020
typedef long long ll;
const ll mod=998244353;
inline ll read(){
    ll x=0,f=1;
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
int n,m,cnt,mid;
ll a[N],d[N],f[28][N],g[N],pcnt[N<<1],ans[N],tmp[N]; 
void Insert(ll x){
	for(int i=m-1;i>=0;--i){
		if((x>>i)&1){
			if(!d[i]){
				d[i]=x,++cnt;
				return;
			}
			else{
				x^=d[i];
			}
		}
	}
}
void dfs1(int u,ll num){
	if(u==mid-1){
		f[pcnt[num>>mid]][num&((1<<mid)-1)]++;
		
		return;
	}
	dfs1(u-1,num);
	if(d[u]){
		dfs1(u-1,num^d[u]);
	}
}
void dfs2(int u,ll num){
	if(u==mid){
		g[num]++;
		return;
	}
	dfs2(u+1,num);
	if(d[u]){
		dfs2(u+1,num^d[u]);
	}
}
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void XOR(ll *f,ll x,int n){
	for(int p=2;p<=n;p<<=1){
		int len=(p>>1);
		for(int k=0;k<n;k+=p){
			for(int i=k;i<k+len;++i){
				ll t1=f[i]+f[i+len],t2=f[i]-f[i+len];
				f[i]=t1*x%mod,f[i+len]=t2*x%mod;
			}
		}
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		Insert(a[i]);
	}
	mid=(m+1)>>1;
	for(int i=1;i<=300000;++i){
		pcnt[i]=pcnt[i>>1]+(i&1);
	}
	dfs1(m-1,0);
	dfs2(0,0);
	memcpy(tmp,g,sizeof(g));
	for(int i=0;i<=m-mid;++i){
		memcpy(g,tmp,sizeof(g));
		XOR(f[i],1,1<<mid);
		XOR(g,1,1<<mid);
		for(int j=0;j<(1<<mid);++j){
			f[i][j]=f[i][j]*g[j]%mod;
		}
		XOR(f[i],qpow(2LL,mod-2),1<<mid);
		for(int j=0;j<(1<<mid);++j){
			ans[i+pcnt[j]]=(ans[i+pcnt[j]]+f[i][j])%mod;
		}
	}
	for(int i=0;i<=m;++i){
		printf("%lld ",ans[i]*qpow(2LL,n-cnt)%mod);
	}
	return 0;
}