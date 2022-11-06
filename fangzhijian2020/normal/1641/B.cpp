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
int T,n,x,a[200005],tot,top,len,ans[5000005];map<int,int>mp;
struct node{int p,c;}sp[5000005];
void insert(int p,int c){
	sp[++tot]=(node){p,c};len+=2;
	for(int i=len;i>=p+3;--i)a[i]=a[i-2];
	a[p+1]=a[p+2]=c;
}
int main(){
	T=read()+1;
	while(--T){
		n=read();mp.clear();len=n;tot=top=0;
		for(int i=1;i<=n;++i)a[i]=read(),++mp[a[i]];
		int opt=0;for(int i=1;i<=n;++i){if(mp[a[i]]&1)opt=1;}
		if(opt)puts("-1");
		else{
			int now=1,tps=0;
			while(now<len){
				int tmp=0;++tps;
				for(int i=now+1;i<=len;++i){
					if(a[now]==a[i]){tmp=i;break;}
				}
				for(int i=now+1;i<tmp;++i){
					insert(tmp+i-now-1,a[i]);
				}
				ans[++top]=(tmp-now)*2;now=tmp-now+tmp;
			}
			cout<<tot<<"\n";
			for(int i=1;i<=tot;++i){
				cout<<sp[i].p<<" "<<sp[i].c<<"\n";
			}
			cout<<top<<"\n";
			for(int i=1;i<=top;++i){
				cout<<ans[i]<<" ";
			}
			puts("");
		}
	}
	return 0;
}