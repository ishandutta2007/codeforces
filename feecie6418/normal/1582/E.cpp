#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int Mxdt=100000,INF=1e9;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int T,n,N,a[100005];long long s[100005],f[100005][505];
int main(){
	T=read()+1;
	while(--T){
		n=read();N=500;
		for(int i=1;i<=n+1;++i)for(int j=0;j<=N;++j)f[i][j]=0;
		for(int i=1;i<=n;++i){
			a[i]=read();s[i]=s[i-1]+a[i],f[i][1]=a[i];
		}
		for(int i=n-1;i;--i){
			for(int j=1;j<=N;++j){
				f[i][j]=max(f[i][j],f[i+1][j]);
				if(i+j>n)break;
				if(s[i+j-1]-s[i-1]<f[i+j][j-1])f[i][j]=max(f[i][j],s[i+j-1]-s[i-1]);
			}
		}
		int Max=0;
		for(int i=1;i<=N;++i)if(f[1][i])Max=i;
		cout<<Max<<"\n";
	}
	return 0;
}