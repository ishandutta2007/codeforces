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
const int N=2e5+1;
set<int>mp;
int n,mod,tot,a[N],c[N];
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V input(){
	n=getint(),mod=getint();
	FOR(i,1,n)a[i]=getint();
	sort(a+1,a+1+n);
}
V init(){
	int l=0,r=a[mod];
	FOR(i,1,n)cmax(l,a[i]-i+1);
	FOR(i,mod,n)mp.insert(mod+a[i]-i);
	FOR(i,l,r)if(mp.find(i)==mp.end())c[++tot]=i;
	cout<<tot<<'\n';
	FOR(i,1,tot)cout<<c[i]<<' ';
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}