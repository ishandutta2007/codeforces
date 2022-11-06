#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000,N=2000000;
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
int n,m,s[505][505],t[505][505],ans;char c[505][505];
int main(){
	n=read();m=read();
	for(int i=1;i<=n;++i){
		scanf("%s",c[i]+1);
	}
	for(int i=n;i;--i){
		for(int j=m;j;--j){
			s[i][j]^=s[i][j+1]^s[i+1][j]^s[i+1][j+1];
			if(c[i][j]=='B'&&!s[i][j])t[i][j]=1;
			if(c[i][j]=='W'&&s[i][j])t[i][j]=1;
			s[i][j]^=t[i][j];
			ans+=t[i][j];
		}
	}
	int opt=0;
	for(int i=1;i<n;++i){
		for(int j=1;j<m;++j){
			if(t[i][j]&&t[n][j]&&t[i][m]&&t[n][m]){
				--ans;opt=1;break;
			}
		}
		if(opt)break;
	}
	cout<<ans<<"\n";
	return 0;
}