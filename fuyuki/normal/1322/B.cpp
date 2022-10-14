#include<bits/stdc++.h>
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
const int N=5e5+2,INF=0x7fffffff,M=1<<24|1;
int n,ans,now,a[N];
struct seg{
	int tot,t[M],cnt0;
	I lowbit(int x){return x&-x;}
	V add(int x,int y){
		tot+=y;
		if(x==0)return void(cnt0+=y);
		while(x<M)t[x]+=y,x+=lowbit(x);
	}
	I ask(int x){
		int out=0;
		while(x)
			out+=t[x],x^=lowbit(x);
		return out+cnt0;
	}
}t[2];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
I calc(int p,int x){
	return t[p].tot-t[p].ask(now-x)+t[p^1].ask(now-x)&1;
}
V work(){
	FOR(p,0,24){
		now=(1<<p)-1;
		FOR(i,1,n){
			if(calc(a[i]>>p&1,a[i]&now))ans^=1<<p;
			t[a[i]>>p&1].add(a[i]&now,1);
		}
		FOR(i,1,n)t[a[i]>>p&1].add(a[i]&now,-1);
	}
	cout<<ans;
}
int main(){
	input();
	work();
	return 0;
}