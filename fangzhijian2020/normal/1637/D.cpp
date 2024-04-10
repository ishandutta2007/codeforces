#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;const long long INF=1e15;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n;long long f[2][20005],sum[500005],a[500005],b[500005];
int main(){
	T=read()+1;
	while(--T){
		n=read();memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)a[i]=read(),sum[i]+=a[i];
		for(int i=1;i<=n;++i)b[i]=read(),sum[i]+=b[i];
		memset(f[0],0x3f,sizeof(f[0]));f[0][0]=0;int now=0;
		for(int i=1;i<=n;++i){
			sum[i]+=sum[i-1]; 
			now^=1;memset(f[now],0x3f,sizeof(f[now]));
			for(int j=0;j<=sum[i];++j){
				if(f[now^1][j]<INF){
					f[now][j+a[i]]=min(f[now][j+a[i]],f[now^1][j]+2ll*a[i]*j+2ll*b[i]*(sum[i-1]-j));
					f[now][j+b[i]]=min(f[now][j+b[i]],f[now^1][j]+2ll*a[i]*(sum[i-1]-j)+2ll*b[i]*j);
				}
			}
		}
		long long ans=INF;
		for(int i=0;i<=sum[n];++i){
			ans=min(ans,f[now][i]); 
		}
		for(int i=1;i<=n;++i){
			ans+=1ll*(n-1)*(a[i]*a[i]+b[i]*b[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}