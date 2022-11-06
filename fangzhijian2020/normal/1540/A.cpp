#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	return getchar();
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
//int Mod(int x){return x<mod?x:x-mod;}
//void Add(int&x,int y){x=Mod(x+y);}
int T,n,d[100005];
int main(){
	T=read()+1;
	while(--T){
		n=read();
		for(int i=1;i<=n;++i)d[i]=read();
		sort(d+1,d+n+1);
		long long sum=0,ans=d[n];
		for(int i=1;i<=n;++i){
			ans-=1ll*d[i]*(i-1)-sum;
			sum+=d[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}