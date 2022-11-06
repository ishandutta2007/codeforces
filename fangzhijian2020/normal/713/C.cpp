#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int Mxdt=100000;const long long INF=1e18;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
long long read(){
	long long a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[3005],tmp[3005],tot;long long f[3005][3005],ans=INF;
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read()-i+1,tmp[++tot]=a[i];
	sort(tmp+1,tmp+tot+1);tot=unique(tmp+1,tmp+tot+1)-tmp-1;
	for(int i=1;i<=n;++i){
		long long Min=INF;
		for(int j=1;j<=tot;++j){
			Min=min(Min,f[i-1][j]);
			f[i][j]=Min+abs(a[i]-tmp[j]);
		}
	}
	for(int i=1;i<=tot;++i)ans=min(ans,f[n][i]);
	cout<<ans<<"\n";
	return 0;
}