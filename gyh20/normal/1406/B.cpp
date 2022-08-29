#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200002];
const int Mxdt=200020;	//???? 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int t=0,f=0;char v=gc();
	while(v<'0')f|=(v=='-'),v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return f?-t:t;
}
signed main(){
	int t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		sort(a+1,a+n+1);
		printf("%lld\n",max(a[1]*a[2]*a[3]*a[4]*a[5],max(a[1]*a[2]*a[3]*a[4]*a[n],max(a[1]*a[2]*a[3]*a[n-1]*a[n],max(a[1]*a[2]*a[n-2]*a[n-1]*a[n],max(a[1]*a[n-3]*a[n-2]*a[n-1]*a[n],a[n-4]*a[n-3]*a[n-2]*a[n-1]*a[n]))))));
	}
}