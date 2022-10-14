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
int T,n,k,minn,a[N],s[N];
int t[N],c[N];
int sa[N],sb[N];
I test(int l,int r){
	static int tot=0,tmp[10];
	tot=0;
	FOR(i,l,r)tmp[++tot]=a[i];
	sort(tmp+1,tmp+tot+1);
	return tmp[tot+1>>1]>=k;
}
V work(){
	minn=INF,n=getint(),k=getint();
	FOR(i,1,n){
		a[i]=getint(),s[i]=s[i-1]+(a[i]>=k)-(a[i]<k),c[i]=c[i-1]+(a[i]==k);
		sa[i]=sa[i-1],sb[i]=sb[i-1];
		if(a[i]<k)sa[i]--;
		if(a[i]==k)sb[i]++;
		if(a[i]>k)sa[i]++;
	}
	FOR(i,1,n+n+4)t[i]=-1;
	if(!c[n])return void(cout<<"no\n");
	if(n==1){
		if(a[1]==k)cout<<"yes\n";
		else cout<<"no\n";
		return;
	}
	FOR(i,1,n)FOR(j,1,4)if(i+j<=n&&test(i,i+j))
		return void(cout<<"yes\n");
	cout<<"no\n";
}
int main(){
	for(scanf("%d",&T);T--;)work();
	return 0;
}