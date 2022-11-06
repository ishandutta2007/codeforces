#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef vector<int> poly;
const int Mxdt=100000,mod=998244353,G=3,N=1e5+1;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?mod-a:a;
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
int w;
struct complex{
	int x,y;
	complex(int X=0,int Y=0){x=X;y=Y;}
	complex operator*(const complex&a){
		return complex((1ll*x*a.x+1ll*y*a.y%mod*w)%mod,(1ll*y*a.x+1ll*x*a.y)%mod);
	}
};
complex ksm(complex a,int n){
	complex ans=complex(1,0);
	while(n){
		if(n&1)ans=ans*a;
		a=a*a;n>>=1;
	}
	return ans;
}
int Sqrt(int x){
	int a,t;
	while(1){
		a=rand();t=Mod(1ll*a*a%mod-x+mod);
		if(ksm(t,(mod-1)>>1)!=1)break;
	}
	w=t;int tmp=ksm(complex(a,1),(mod+1)>>1).x;
	return min(tmp,mod-tmp);
}
namespace Poly{
	int fr[262144],inv[262145],tot,O[524288],w[262144];
	int maketable(int n){
		int m=1;while(m<n)m<<=1;
		for(int i=1;i<m;++i){
			fr[i]=(fr[i>>1]>>1)|(i&1?m>>1:0);
		}
		return m;
	}
	void prework(int n){
		int N=maketable(n);
		inv[1]=1;for(int i=2;i<=N;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		int g=ksm(G,(mod-1)/N);O[0]=1;for(int i=1;i<N;++i)O[i]=1ll*O[i-1]*g%mod;
		tot=N-1;for(int j=2;j<=N;j<<=1)for(int i=0;i<N;i+=j)O[++tot]=O[i];
	}
	poly rev(poly f){
		reverse(f.begin(),f.end());
		return f;
	}
	poly div(poly f,int n){
		f.resize(n);return f;
	}
	poly sig(poly f){
		int n=f.size();
		for(int i=n-1;i;--i){
			f[i]=1ll*f[i-1]*inv[i]%mod;
		}
		f[0]=0;return f;
	}
	poly der(poly f){
		int n=f.size();
		for(int i=1;i<n;++i){
			f[i-1]=1ll*f[i]*i%mod;
		}
		f[n-1]=0;
		return f;
	}
	void NTT(poly&f,int n,int opt){
		int t=tot;f.resize(n);
		for(int i=1;i<n;++i)if(i<fr[i])swap(f[i],f[fr[i]]);
		for(int i=2;i<=n;t-=i,i<<=1){
			int len=(i>>1);
			if(opt)for(int j=0;j<len;++j)w[j]=O[t-j];
			else for(int j=0;j<len;++j)w[j]=O[t-i+j];
			for(int j=0;j<n;j+=i){
				for(int k=j;k<j+len;++k){
					int tmp=1ll*f[k+len]*w[k-j]%mod;
					f[k+len]=f[k]<tmp?f[k]-tmp+mod:f[k]-tmp;
					f[k]=f[k]+tmp<mod?f[k]+tmp:f[k]+tmp-mod;
				}
			}
		}
		if(opt){
			for(int i=0;i<n;++i)f[i]=1ll*f[i]*inv[n]%mod;
		}
	}
	poly operator+(poly f,poly g){
		int n=max(f.size(),g.size());f.resize(n);
		for(int i=0;i<g.size();++i)Add(f[i],g[i]);
		return f;
	}
	poly operator+(poly f,int g){
		Add(f[0],g);return f;
	}
	poly operator-(poly f,poly g){
		int n=max(f.size(),g.size());f.resize(n);
		for(int i=0;i<g.size();++i)Add(f[i],mod-g[i]);
		return f;
	}
	poly operator*(poly f,int g){
		int n=f.size();
		for(int i=0;i<n;++i)f[i]=1ll*f[i]*g%mod;
		return f;
	}
	poly operator*(poly f,poly g){
		int n=f.size()+g.size()-1;
		if(n<=100){
			poly h;h.resize(n);
			for(int i=0;i<f.size();++i){
				for(int j=0;j<g.size();++j){
					Add(h[i+j],1ll*f[i]*g[j]%mod);
				}
			}
			return h;
		}
		int len=maketable(n);
		NTT(f,len,0);NTT(g,len,0);
		for(int i=0;i<len;++i)f[i]=1ll*f[i]*g[i]%mod;
		NTT(f,len,1);f.resize(n);return f;
	}
	poly INV(poly f){
		poly g,tmp;int m=f.size();
		g.push_back(ksm(f[0],mod-2));
		for(int n=2;(n>>1)<m;n<<=1){
			tmp=div(f,n);
			g=g*2-g*g*tmp;g.resize(n);
		}
		g.resize(m);return g;
	}
	poly operator/(poly f,poly g){
		int n=f.size()-g.size()+1;
		if(n<=0){poly tmp;tmp.resize(1);return tmp;}
		return rev(div(div(rev(f),n)*INV(div(rev(g),n)),n));
	}
	poly operator%(poly f,poly g){
		poly tmp=f/g;int m=g.size()-1;
		return div(f-tmp*g,m);
	}
	poly SQRT(poly f){
		poly g,tmp;int m=f.size();
		g.push_back(Sqrt(f[0]));
		for(int n=2;(n>>1)<m;n<<=1){
			tmp=div(f,n);g.resize(n);
			g=(tmp*INV(g)+g)*inv[2];g.resize(n);
		}
		g.resize(m);return g;
	}
	poly LN(poly f){
		int n=f.size();
		return sig(div(der(f)*INV(f),n));
	}
	poly EXP(poly f){
		poly g,tmp;int m=f.size();
		g.push_back(1);
		for(int n=2;(n>>1)<m;n<<=1){
			tmp=div(f,n);g.resize(n);
			g=g*(tmp-LN(g)+1);g.resize(n);
		}
		g.resize(m);return g;
	}
	poly KSM(poly f,int n){
		return EXP(LN(f)*n);
	}
};
int n,m,k,sum,t;poly f,g;
int main(){
	using namespace Poly;
	n=read();m=read()+1;f.resize(N);prework(N<<1);
	for(int i=1;i<=n;++i)f[read()]=1;
	f=INV(SQRT((f*(mod-4))+1)+1)*2;
	for(int i=1;i<m;++i)cout<<f[i]<<"\n";
	return 0;
}