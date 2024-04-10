#include<cmath>
#include<cstdio>
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
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
LL getint(){
	re ll _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=3e5+100,INF=0x7fffffff;
int n,tot;
int a[N],val[N];
V input(){
	n=getint(),tot=0;
	FOR(i,1,n)a[i]=val[++tot]=getint();
}
I find(rnt x){
	rnt l=1,r=tot,mid;
	while(mid=l+r>>1,l^r)
		if(val[mid+1]<=x)l=mid+1;
		else r=mid;
	return mid;
}
int L[N],R[N];
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
V init(){
	sort(val+1,val+1+tot),tot=unique(val+1,val+1+tot)-val-1;
	FOR(i,1,n)a[i]=find(a[i]),L[i]=INF,R[i]=-INF;
	FOR(i,1,n)L[a[i]]=min(L[a[i]],i),R[a[i]]=max(R[a[i]],i);
}
V work(){
	rnt cur=1,ans=tot,p;
	while(cur<=tot){
		p=cur;
		while(L[p+1]>R[p]&&p<tot)p++;
		ans=min(ans,tot-(p-cur+1));
		cur=p+1;
	}
	cout<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}