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
const int N=4e5+2,INF=1e9;
int n,pre[N][26],nxt[N][26];
long long ans;
char a[N];
V input(){
	scanf("%s",a+1),n=strlen(a+1);
}
V init(){
	ROF(i,n,1)FOR(j,0,25)nxt[i][j]=nxt[i+1][j]+(a[i]==j+'a');
}
V work(){
	FOR(i,0,25)FOR(j,0,25){
		ll now=0;
		FOR(k,1,n)if(a[k]==i+'a')
			now+=nxt[k+1][j];
		ans=max(ans,now);
	}
	FOR(i,0,25)ans=max(ans,(ll)nxt[1][i]);
	cout<<ans<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}