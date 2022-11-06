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
int T,n,s[1000005];char c[1000005];
int main(){
	T=read()+1;
	while(--T){
		n=read();scanf("%s",c+1);
		for(int i=1;i<=n;++i){
			s[i]=s[i-1]+(c[i]=='a'?1:-1);
		}
		int opt=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(s[j]-s[i-1]==0){
					cout<<i<<" "<<j<<"\n";
					opt=1;break;
				}
			}
			if(opt)break;
		}
		if(!opt){
			puts("-1 -1");
		}
	}
	return 0;
}