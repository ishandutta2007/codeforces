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
int T,n,a[10005],b[10005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)a[i]=b[i]=read();
		sort(b+1,b+n+1);int opt=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[i])opt=1;
		} 
		puts(opt?"YES":"NO");
	}
	return 0;
}