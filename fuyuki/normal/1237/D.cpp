#include<set>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=4e5+100;
int n,lim,rt,a[N];
int ans,tot,maxn,minn=0x7fffffff;
V input(){
	n=getint();
	FOR(i,1,n)a[i]=a[i+n]=a[i+n+n]=a[i+n+n+n]=getint(),maxn=max(maxn,a[i]),minn=min(minn,a[i]);
}
multiset<int>mp;
I top(){
	multiset<int>::iterator it=mp.end();
	return *--it;
}
V work(){
	if(minn*2>=maxn){
		FOR(i,1,n)cout<<"-1 ";
		return;
	}
	rnt cur=0,x;mp.insert(0);
	FOR(i,1,n){
		while((x=top())<=a[cur+1]*2)
			mp.insert(a[++cur]);
		cout<<cur-i+1<<' ';
		mp.erase(mp.find(a[i]));
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	input();
	work();
	return 0;
}