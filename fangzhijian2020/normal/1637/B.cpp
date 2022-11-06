#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000;
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
int T,n,a[105],mex[105][105],vis[105],f[105][105];long long ans=0;
int main(){
	T=read()+1;
	while(--T){
		n=read();ans=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=1;i<=n;++i){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;++j){
				if(a[j]<=n)vis[a[j]]=1;
				mex[i][j]=0;
				while(vis[mex[i][j]])++mex[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			f[i][i-1]=0;
			for(int j=i;j<=n;++j){
				f[i][j]=0;
				for(int k=i-1;k<j;++k){
					f[i][j]=max(f[i][j],f[i][k]+mex[k+1][j]+1);
				}
				ans+=f[i][j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}