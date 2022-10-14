#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=3e5+10;
ll ans;
int n,a[N],t[N],id[N];
priority_queue<int>q;
I cmp(int x,int y){
	return a[x]<a[y];
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint(),id[i]=i;
	FOR(i,1,n)t[i]=getint();
//		now=x;
}
V init(){
	sort(id+1,id+1+n,cmp);
}
V work(){
	int now=0,cur=1;ll sum=0;
	while(cur<=n){
		int x=a[id[cur]];
		while(now<x&&!q.empty())
			sum-=q.top(),q.pop(),ans+=sum,now++;
		now=x;
		while(x==now&&cur<=n)
			q.push(t[id[cur]]),sum+=t[id[cur]],x=a[id[++cur]];
		sum-=q.top(),q.pop(),ans+=sum,now++;
	}
	while(!q.empty())
		sum-=q.top(),q.pop(),ans+=sum;
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}