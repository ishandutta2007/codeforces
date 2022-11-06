#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int T,n,H,ans,a[1005];
int main(){
	T=read()+1;
	while(--T){
		n=read();H=read();ans=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		sort(a+1,a+n+1);
		ans+=(H/(a[n]+a[n-1]))*2;
		H=H%(a[n]+a[n-1]);
		if(H)++ans;
		if(H>a[n])++ans;
		cout<<ans<<"\n";
	}
	return 0;
}