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
int T,n;long long sum,a[500005];
int main(){
	T=read()+1;
	while(--T){
		n=read();sum=0;int opt=0,pp=0;
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=2;i<n;++i){
			sum+=a[i];if(a[i]&1)++sum;
			if((!(a[i]&1)))opt=1;
			if(a[i]>2)pp=1;
		}
		if(pp&&n>3)opt=1;
		if(!opt)puts("-1");
		else cout<<sum/2<<"\n";
	}
	return 0;
}