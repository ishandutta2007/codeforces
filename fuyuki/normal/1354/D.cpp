#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1;
int n,m,siz,t[N];
I lowbit(int x){return x&-x;}
V add(int x,int y){while(x<=n)t[x]+=y,x+=lowbit(x);}
I kth(int x){
	int p=1,v=0;
	if(x<=t[1])return 1;
	while(p*2<=n&&t[p*2]<x)p<<=1;
	for(v=p,x-=t[p];p>>=1;)if(v+p<=n&&t[v+p]<x)x-=t[v|=p];
	return v+1;
}
int main(){
	siz=n=getint(),m=getint();
	FOR(i,1,n)add(getint(),1);
	for(int x;m--;){
		x=getint();
		if(x<0)siz--,add(kth(-x),-1);
		else siz++,add(x,1);
	}
	if(!siz)cout<<0<<'\n';
	else cout<<kth(1)<<'\n';
	return 0;
}