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
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=3e5+2,sgn[2]={1,-1},INF=0x3f3f3f3f;
int T,n,k,tot;
int a[N],c[N],tag[N],ans[N];
V input(){
	n=getint(),tot=k=0;
	FOR(i,1,n)a[i]=getint(),tag[i]=0;
}
I mex(){
	static int cnt[N];
	FOR(i,0,n)cnt[i]=0;
	FOR(i,1,n)cnt[a[i]]++;
	FOR(i,0,n)if(!cnt[i])return i;
}
I no(){
	FOR(i,1,n-1)if(a[i]>a[i+1])return 1;
	return 0;
}
V work(){
	for(int p;no();){
		if(mex()==n){
			FOR(i,1,n)c[a[i]]=i;
			ROF(i,n-1,0)if(c[i]!=i+1){
				ans[++k]=c[i],a[c[i]]=n;
				break;
			}
		}
		else p=mex(),a[p+1]=p,ans[++k]=p+1;
		
	}
	cout<<k<<'\n';
	FOR(i,1,k)cout<<ans[i]<<" \n"[i==k];
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		work();
	}
	return 0;
}