#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=5e5+1;
int T,n,k;
char a[N];
V input(){scanf("%d%d%s",&n,&k,a+1);}
V init(){
	int A=0,B=0,C=0;
	FOR(i,1,k){
		int c[2]={0,0};
		for(int x=i;x<=n;x+=k)if(a[x]!='?')
			c[a[x]-'0']++;
		if(c[0]&&c[1])return void(cout<<"NO\n");
		if(!c[0]&&!c[1])C++;
		else if(c[0])A++;
		else if(c[1])B++;
	}
	if(A<=k/2&&B<=k/2)cout<<"YES\n";
	else cout<<"NO\n";
}
V work(){
	
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}