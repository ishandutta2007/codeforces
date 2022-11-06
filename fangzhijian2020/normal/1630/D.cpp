#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
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
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int T,n,m,a[1000005],b[1000005];
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();
		for(int i=1;i<=n;++i)a[i]=read();
		int t=0;
		for(int i=1;i<=m;++i){
			b[i]=read();t=gcd(t,b[i]);
		}
		long long ans=0,sum1=0,sum2=0;
		for(int i=1;i<=n;++i){
			ans+=abs(a[i]);
		}
//		if(t!=1){
			for(int i=1;i<=t;++i){
				int Min=INF,opt=0;
				for(int j=i;j<=n;j+=t){
					Min=min(Min,abs(a[j]));
					if(a[j]<0)opt^=1;
					if(a[j]==0)opt=2; 
				}
				if(opt==0)sum1+=Min;
				if(opt==1)sum2+=Min;
			}
			ans-=2*min(sum1,sum2);
//		}
		cout<<ans<<"\n";
	}
	return 0;
}