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
char c[1000005];int z[10000005],n,ans,st,Max;
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(int i=2,l=0,r=0;i<=n;++i){
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&c[i+z[i]]==c[z[i]+1])++z[i];
		if(i+z[i]-1>=r){l=i;r=i+z[i]-1;}
	}
	for(int i=2;i<n;++i){
		Max=max(Max,min(z[i],n-i));
	}
	for(int i=2;i<=n;++i){
		if(i+z[i]-1==n&&z[i]<=Max){
			st=i;ans=z[i];break;
		}
	}
	if(!ans)puts("Just a legend");
	else{
		for(int i=st;i<st+ans;++i)putchar(c[i]);
	}
	return 0;
}