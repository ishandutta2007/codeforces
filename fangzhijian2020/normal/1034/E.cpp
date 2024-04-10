#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int Read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int read(){
	char c=gc();
	while(c<'0'||c>'9')c=gc();return c^48;
}
int n,sz[1<<21];unsigned long long mi[25],a[1<<21],b[1<<21];
int main(){
	n=Read();
	for(int i=1;i<(1<<n);++i)sz[i]=sz[i>>1]+(i&1);
	mi[0]=1;for(int i=1;i<=n;++i)mi[i]=mi[i-1]<<2;
	for(int i=0;i<(1<<n);++i)a[i]=read()*mi[sz[i]];
	for(int i=0;i<(1<<n);++i)b[i]=read()*mi[sz[i]];
	for(int i=1;i<(1<<n);i<<=1){
		for(int j=1;j<(1<<n);++j){
			if(i&j)a[j]+=a[i^j],b[j]+=b[i^j];
		}
	}
	for(int i=0;i<(1<<n);++i)a[i]=a[i]*b[i];
	for(int i=1;i<(1<<n);i<<=1){
		for(int j=1;j<(1<<n);++j){
			if(i&j)a[j]-=a[i^j];
		}
	}
	for(int i=0;i<(1<<n);++i){
		a[i]/=mi[sz[i]];putchar(a[i]%4+'0');
	}
	return 0;
}