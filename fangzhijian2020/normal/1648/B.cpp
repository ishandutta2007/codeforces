#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,N=2000000,mod=998244353,base=2333333,inv=222430835;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p1=(p2=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,c,a[1000005],h[1000005],sum[1000005];
int main(){
	T=read()+1;
	while(--T){
		n=read();c=read();int opt=1;
		for(int i=1;i<=c;++i)sum[i]=h[i]=0;
		for(int i=1;i<=n;++i)++h[read()];
		for(int i=1;i<=c;++i)sum[i]=sum[i-1]+h[i];
		for(int i=1;i<=c;++i){
			if(!h[i]){
				for(int j=1;i*j<=c;++j){
					if(h[j]&&(sum[min(c,j*(i+1)-1)]-sum[min(c,j*i-1)])>0)opt=0;
				}
			}
		}
		puts(opt?"Yes":"No");
	}
	return 0;
}