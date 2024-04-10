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
const int N=2e5+2;
int n,k,a[N];
ll pre[N],suf[N],ans=1ll<<62;
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){sort(a+1,a+1+n);}
V work(){
	FOR(i,1,n)pre[i]=pre[i-1]+a[i];
	ROF(i,n,1)suf[i]=suf[i+1]+a[i];
	for(int l=1,r;l<=n;l=r+1){
		for(r=l;a[r+1]==a[l];r++);
		if(r-l+1>=k)return void(cout<<0);
		ll tmp=0;
		tmp+=1ll*(a[l]-1)*(l-1)-pre[l-1];
		tmp+=suf[r+1]-1ll*(a[r]+1)*(n-r);
		tmp+=k-(r-l+1);
		if(ans>tmp)ans=tmp;
		if(r>=k){
			tmp=1ll*(a[l]-1)*(l-1)-pre[l-1]+k-(r-l+1);
			if(ans>tmp)ans=tmp;
		}
		if(n-l+1>=k){
			tmp=suf[r+1]-1ll*(a[r]+1)*(n-r)+k-(r-l+1);
			if(ans>tmp)ans=tmp;
		}
	}
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}