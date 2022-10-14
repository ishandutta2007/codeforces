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
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	re int _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
V getstr(char*out,int&len){
	re char ch=gc;len=0;
	while(ch<'0'||ch>'9')ch=gc;
	while(ch>='0'&&ch<='9')out[++len]=ch,ch=gc;
}
I lowbit(const int&x){return x&-x;}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=5e5+100;
int n,k;
char a[N];
/*
struct edge{int t,n;}e[N<<1];
int h[N],tot=1,d[N];
V add_edge(rnt x,rnt y){
	e[++tot]=(edge){y,h[x]},h[x]=tot;
	e[++tot]=(edge){x,h[y]},h[y]=tot;
	d[x]++,d[y]++;
}
*/
V input(){n=getint(),k=getint(),getstr(a,n);}
V init(){
	if(!k)return void(cout<<a+1);
	if(n==1)return void(cout<<"0");
	if(a[1]!='1')a[1]='1',k--;
	FOR(i,2,n)if(k&&a[i]!='0')k--,a[i]='0';
	cout<<a+1;
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