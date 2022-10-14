#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
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
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e5+1,INF=0x3f3f3f3f;
char a[N];
int n,m,s[26][N];
V input(){scanf("%s",a+1),n=strlen(a+1);}
V init(){
	FOR(i,1,n){
		FOR(j,0,25)s[j][i]=s[j][i-1];
		s[a[i]-'a'][i]++;
	}
}
I ask(int l,int r){
	int out=0;
	FOR(i,0,25)out+=!!(s[i][r]-s[i][l-1]);
	return out;
}
char ans[2][10]={"No\n","Yes\n"};
I query(int l,int r){
	if(l==r)return 1;
	int x=ask(l,r),y,cx,cy;
	if(x==1)return 0;
	if(x>=3)return 1;
	x=-1,y=-1;
	FOR(i,0,25)if(s[i][r]-s[i][l-1]){
		if(!~x)x=i,cx=s[i][r]-s[i][l-1];
		else y=i,cy=s[i][r]-s[i][l-1];
	}
	if(a[l]!=x+'a')swap(x,y),swap(cx,cy);
	cx-=(a[r]==x+'a');
	return cx+cy>r-l;
}
V work(){
	scanf("%d",&m);int l,r;
	while(m--){
		scanf("%d%d",&l,&r);
		cout<<ans[query(l,r)];
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}