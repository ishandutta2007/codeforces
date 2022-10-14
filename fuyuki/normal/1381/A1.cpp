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
const int N=2e5+100,INF=0x3f3f3f3f;
char a[N],b[N],c[N];
int T,n,m,out[N];
V input(){
	scanf("%d%s%s",&n,a+1,b+1),m=0;
	FOR(i,1,n)c[i]=a[i];
}
V rev(int x){
//	FOR(i,1,x)c[i]^=1;
//	reverse(c+1,c+1+x);
	out[++m]=x;
}
V init(){
	int l=1,r=n,p=n,flag=1,now=0;
	ROF(i,n,1){
		if((a[flag?r:l]^now)!=b[i]){
			if((a[flag?l:r]^now)!=(b[i]^1))
				rev(1);
			rev(i),flag^=1,now^=1;
		}
		if(flag)r--;
		else l++;
	}
	cout<<m<<' ';
	FOR(i,1,m)cout<<out[i]<<" \n"[i==m];
//	FOR(i,1,n)if(b[i]!=c[i])cerr<<"fuck\n";
}
V work(){
}
int main(){
//	freopen("test.in","r",stdin);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}