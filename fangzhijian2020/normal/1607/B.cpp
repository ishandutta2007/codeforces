#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
long long read(){
	long long a=0;bool opt=0;char c=gc();
	while(c<'0')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T;long long x,n,tmp;
int main(){
	T=read()+1;
	while(--T){
		x=read();n=read();
		if(n==0)tmp=0;
		else{
			long long t=(n-1)/2;
			if(t&1){
				if(n&1){
					tmp=-(t+1)*2+n+1+n+2;
				}
				else{
					tmp=-(t+1)*2+n+1;
				}
			}
			else{	
				if(n&1){
					tmp=-t*2;
				}
				else{
					tmp=-t*2+n;
				}
			}
			tmp-=1;	
		}
		if(x&1)cout<<x-tmp<<"\n";
		else cout<<x+tmp<<"\n";
	}
	return 0;
}