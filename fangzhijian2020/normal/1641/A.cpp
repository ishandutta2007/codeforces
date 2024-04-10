#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int Mxdt=100000,mod=998244353,INF=1e9;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2),*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int T,n,x,a[200005],ans;map<int,int>mp;
int main(){
	T=read()+1;
	while(--T){
		n=read();x=read();mp.clear();ans=0;
		for(int i=1;i<=n;++i)a[i]=read(),++mp[a[i]];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i){
			if(mp[a[i]]){
				if(1ll*a[i]*x<=INF){
					int tmp=min(mp[a[i]],mp[a[i]*x]);
					mp[a[i]]-=tmp;mp[a[i]*x]-=tmp;
				}
				ans+=mp[a[i]];mp[a[i]]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}