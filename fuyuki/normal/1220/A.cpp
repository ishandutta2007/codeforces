#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<stack>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
V getstr(char*out,int&len){
	re char ch=gc;len=0;
	while(ch<'a'||ch>'z')ch=gc;
	while(ch>='a'&&ch<='z')out[++len]=ch,ch=gc;
}
const int N=1e5+100;
char st[N];
int n,s1,s2;
V input(){n=getint();getstr(st,n);}
V init(){
	
}
V work(){
	FOR(i,1,n)
		if(st[i]=='n')s1++;
		else if(st[i]=='z')s2++;
	FOR(i,1,s1)cout<<"1 ";
	FOR(i,1,s2)cout<<"0 ";
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}