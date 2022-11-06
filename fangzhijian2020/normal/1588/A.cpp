#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int Mxdt=100000,del=8001;
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
int T,n,a[105],b[105],h[205],t[205],B[205];
int main(){
	T=read()+1;
	while(--T){
		memset(h,0,sizeof(h));
		memset(t,0,sizeof(t));
		memset(B,0,sizeof(B));
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read()+100;++h[a[i]];
		}
		for(int i=1;i<=n;++i){
			b[i]=read()+100;++t[b[i]];
		}
		int opt=1;
		for(int i=200;~i;--i){
			if(t[i]<h[i]-B[i]||B[i]>h[i]){
				opt=0;break;
			}
			else if(t[i]>h[i]-B[i]){
				B[i-1]+=(t[i]-h[i]+B[i]);
			}
		}
		puts(opt?"YES":"NO");
	}
	return 0;
}