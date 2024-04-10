#pragma GCC optimize(2) 
#pragma GCC target("avx,sse2,sse3,sse4,mmx") 
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Mxdt=100000;
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj) {
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read() {
	int res=0;
	char ch=gc();
	while(ch<'0')ch=gc();
	while(ch>='0')res=(res<<3)+(res<<1)+(ch^48),ch=gc();
	return res;
}
void print(int x) {
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch) {
	if(x<0)pc('-',false),x=-x;
	print(x),pc(ch,false);
}

const int xx=5e5+5;
int n,a[xx],t[xx];
queue<int>q;
int B;
int bel(int x){return (x-1)/B+1;}
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return bel(l)==bel(w.l)?bel(l)&1?r<w.r:r>w.r:l<w.l;}
}e[xx];
int vis[xx];
void add(int x)
{
	t[a[x]]++;
	if(t[a[x]]==1&&!vis[a[x]])q.push(a[x]),vis[a[x]]=1;
}
void erase(int x)
{
	t[a[x]]--;
	if(t[a[x]]==1&&!vis[a[x]])q.push(a[x]),vis[a[x]]=1;
}
int res[xx];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int m=read();
	B=sqrt(m);
	for(int i=1;i<=m;i++)e[i].id=i,e[i].l=read(),e[i].r=read();
	sort(e+1,e+m+1);
	int l=1,r=0;
	for(int i=1;i<=m;i++)
	{
		while(r<e[i].r)add(++r);
		while(l>e[i].l)add(--l);
		while(r>e[i].r)erase(r--);
		while(l<e[i].l)erase(l++);
		while(!q.empty()&&t[q.front()]!=1)vis[q.front()]=0,q.pop();
		res[e[i].id]=q.size()?q.front():0;
	}
	for(int i=1;i<=m;i++)printnum(res[i],'\n');
	return pc('0',1);
}