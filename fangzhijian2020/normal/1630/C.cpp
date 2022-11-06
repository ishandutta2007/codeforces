#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
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
int T,n,a[200005],h[200005],Next[200005],ans;
int main(){
//	T=read()+1;
//	while(--T){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		for(int i=n;i>=1;--i){
			Next[i]=h[a[i]];
			if(h[a[i]]==0)h[a[i]]=i;
		}
		int r=1,p=0;
		for(int i=1;i<=n;++i){
			if(i<r){
				p=max(p,Next[i]);
			}
			else if(i==r){
				p=max(p,Next[i]);
				if(p>r){
					ans+=p-r-1;r=p;
				}
			}
			else{
				if(Next[i]>i){
					r=Next[i];ans+=Next[i]-i-1;
				}
			}
		}
		cout<<ans<<"\n";
//	}
	return 0;
}