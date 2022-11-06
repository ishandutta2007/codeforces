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
int T,n,k;
int main(){
	T=read()+1;
	while(--T){
		n=read();k=read();
		if(k!=n-1){
			cout<<k<<" "<<n-1<<"\n";
			if(k!=0)cout<<0<<" "<<((n-1)^k)<<"\n";
			for(int i=1;i<n/2;++i){
				if(i!=k&&i!=((n-1)^k))cout<<i<<" "<<((n-1)^i)<<"\n";
			}
		}
		else{
			if(n==4)puts("-1");
			else{
				cout<<n-1<<" "<<n-2<<"\n";
				cout<<1<<" "<<3<<"\n";
//				if(((n-1)&(n-2))+(1&2)!=n-1)cout<<((n-1)&(n-2))+(1&2)<<":::::\n";
				cout<<0<<" "<<((n-1)^3)<<"\n";
				for(int i=2;i<n/2;++i){
					if(i!=3)cout<<i<<" "<<((n-1)^i)<<"\n";
				}
			}	
		}
	}
	return 0;
}