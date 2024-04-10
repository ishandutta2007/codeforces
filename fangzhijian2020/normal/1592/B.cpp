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
int T,n,k,a[100005],b[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		for(int i=1;i<=n;++i){
			a[i]=b[i]=read();
		}
		sort(b+1,b+n+1);
		int opt=1;
		for(int i=n-k+1;i<=k;++i){
			if(a[i]!=b[i])opt=0;
		}
		puts(opt?"YES":"NO");
	}
	return 0;
}