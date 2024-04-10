#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1,mod=1e9+7;
int n,m,t[N],a[N],b[N],d[N],id[N];
set<int>mp[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,m)a[i]=getint(),b[i]=getint();
	FOR(i,1,n)t[i]=getint();
	FOR(i,1,m){
		mp[a[i]].insert(t[b[i]]);
		mp[b[i]].insert(t[a[i]]);
	}
}
I getval(set<int>&x){
	int now=1;
	while(!x.empty()&&*x.begin()==now)
		x.erase(x.begin()),now++;
	return now;
}
I cmp(int x,int y){return t[x]<t[y];}
V init(){
	FOR(i,1,n)if(getval(mp[i])!=t[i])
		return void(cout<<"-1\n");
	FOR(i,1,n)id[i]=i;
	sort(id+1,id+1+n,cmp);
	FOR(i,1,n)cout<<id[i]<<' ';
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(T=getint();T--;){
		input();
		init();
		work();
//	}
	return 0;
}