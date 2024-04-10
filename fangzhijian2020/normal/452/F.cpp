#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int base=131;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	int res=0,bj=0;char ch=gc();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return bj?-res:res;
}
int T,n,t[300005],opt;
unsigned long long a[2][300005],mi[300005];
void add(int opt,int x){
	unsigned long long val=mi[opt?n-x+1:x];
	for(;x<=n;x+=x&-x)a[opt][x]+=val;
}
unsigned long long ask(int opt,int x){
	unsigned long long ans=0;
	for(;x;x-=x&-x)ans+=a[opt][x];
	return ans;
}
bool Hash(int l,int r,int L,int R){
	unsigned long long p=ask(0,r)-ask(0,l-1),q=ask(1,R)-ask(1,L-1);
	int t=l-(n-R+1);if(t>=0)return p==q*mi[t];else return p*mi[-t]==q;
}
bool check(int x){
	int len=min(x-1,n-x);if(!len)return 0;
	if(Hash(max(1,x-len),x-1,x+1,min(n,x+len)))return 0;
	return 1;
}
int main(){
	n=read();mi[0]=1;
	for(int i=1;i<=n;++i)mi[i]=mi[i-1]*base;
	opt=0;memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i)t[i]=read();
	for(int i=1;i<=n;++i){
		if(check(t[i])){opt=1;break;}
		add(0,t[i]);add(1,t[i]);
	}
	puts(opt?"YES":"NO");
	return 0;
}