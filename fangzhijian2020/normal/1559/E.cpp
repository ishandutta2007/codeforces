#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> poly;
const int mod=998244353,G=3,inv2=499122177;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
namespace Poly{
	int fr[262144],fac[262145],ifac[262145],inv[262145],g[524288],w[262144],tot;
	int maketable(int m){
		int n=1;while(n<m)n<<=1;
		for(int i=1;i<n;++i){
			fr[i]=(fr[i>>1]>>1)|(i&1?n>>1:0);
		}
		return n;
	}
	void pre(int n){
		int N=maketable(n<<1);
		inv[1]=1;for(int i=2;i<=N;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%mod;
		ifac[N]=ksm(fac[N],mod-2);for(int i=N;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
		int tG=ksm(G,(mod-1)/N);g[0]=1;for(int i=1;i<N;++i)g[i]=1ll*g[i-1]*tG%mod;
		tot=N-1;for(int i=2;i<=N;i<<=1)for(int j=0;j<N;j+=i)g[++tot]=g[j];
	}
	void NTT(poly&f,int n,bool opt){
		int i,j,k,t=tot;
		for(i=0;i<n;++i)if(i<fr[i])swap(f[i],f[fr[i]]);
		for(i=2;i<=n;t-=i,i<<=1){
			int len=i>>1;
			if(opt)for(j=0;j<len;++j)w[j]=g[t-j];
			else for(j=0;j<len;++j)w[j]=g[t-i+j];
			for(j=0;j<n;j+=i){
				for(k=j;k<j+len;++k){
					int tmp=1ll*f[k+len]*w[k-j]%mod;
					f[k+len]=f[k]<tmp?f[k]-tmp+mod:f[k]-tmp;
					f[k]=f[k]+tmp<mod?f[k]+tmp:f[k]+tmp-mod;
				}
			}
		}
		if(opt){
			int inv=ksm(n,mod-2);for(i=0;i<n;++i)f[i]=1ll*f[i]*inv%mod;
		}
	}
	poly operator*(poly f,poly g){
		poly h;int n=f.size()+g.size()-1;
		if(n<=100){
			h.resize(n);
			for(int i=0;i<f.size();++i){
				for(int j=0;j<g.size();++j){
					Add(h[i+j],1ll*f[i]*g[j]%mod);
				}
			}
			return h;
		}
		int len=maketable(n);
		f.resize(len);g.resize(len);h.resize(len);
		NTT(f,len,0);NTT(g,len,0);
		for(int i=0;i<len;++i)h[i]=1ll*f[i]*g[i]%mod;
		NTT(h,len,1);h.resize(n);
		return h;
	}
	poly operator*(poly f,int g){
		for(int i=0;i<f.size();++i)f[i]=1ll*f[i]*g%mod;
		return f;
	}
	poly operator+(poly f,poly g){
		f.resize(max(f.size(),g.size()));
		for(int i=0;i<g.size();++i)f[i]=Mod(f[i]+g[i]); 
		return f;
	}
	poly operator+(poly f,int g){
		Add(f[0],g);return f;
	}
	poly operator-(poly f,poly g){
		f.resize(max(f.size(),g.size()));
		for(int i=0;i<g.size();++i)f[i]=Mod(f[i]-g[i]+mod); 
		return f;
	}
};
int n,m,l[100005],r[100005],ans,prime[100005],mul[100005],Tot,vis[100005],s[100005];
poly f,h;
int main(){
	using namespace Poly;
	n=read();m=read();
	Poly::pre(m+1);
	mul[1]=1;
	for(int i=2;i<=m;++i){
		if(!vis[i]){
			prime[++Tot]=i;mul[i]=mod-1;
		}
		for(int j=1;j<=Tot;++j){
			if(i*prime[j]>m)break;
			vis[i*prime[j]]=1;
			mul[i*prime[j]]=mod-mul[i];
			if(i%prime[j]==0){
				mul[i*prime[j]]=0;break;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;++i)l[i]=read(),r[i]=read();
	for(int j=1;j<=m;++j){
		if(mul[j]&&j*n<=m){
			f.clear();f.resize(m/j+1);
			for(int i=1;i<=n;++i){
				if(i==1){
					for(int k=j;k<=m;k+=j){
						if(l[i]<=k&&k<=r[i]&&k+(n-1)*j<=m){
							f[k/j]=1;
						}
					}	
				}
				else{
					s[0]=0;
					for(int k=j;k<=m;k+=j){
						s[k/j]=(s[k/j-1]+f[k/j])%mod;
						f[k/j]=(s[max(0,(k-l[i])/j)]-s[max(0,(k-r[i])/j-1)]+mod)%mod;
					}
				}
			}
			for(int i=1;i<=m/j;++i){
				ans=(ans+1ll*mul[j]*f[i]%mod)%mod;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}