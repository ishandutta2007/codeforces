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
#define FOR(i,a,b) for(i=a;i<=b;i++)
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
const int N=10;
int n,m,ans,d[N][N],c[N][N],a[N];
V input(){
	n=getint(),m=getint();rnt x,y,i;
	FOR(i,1,m)x=getint(),y=getint(),d[x][y]=d[y][x]=1;
}
I get_ans(){
	rnt i,j,out=0;
	FOR(i,1,6)FOR(j,1,6)c[i][j]=1;
	FOR(i,1,n)FOR(j,1,n)if(d[i][j]&&c[a[i]][a[j]])
		out++,c[a[i]][a[j]]=c[a[j]][a[i]]=0;
	return out;
}
V work(){
	if(n<=6)return void(cout<<m);
	FOR(a[1],1,6)FOR(a[2],1,6)FOR(a[3],1,6)FOR(a[4],1,6)FOR(a[5],1,6)FOR(a[6],1,6)FOR(a[7],1,6)
		ans=max(ans,get_ans());
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}