#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re //register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e3+1;
int n,ans,a[N],bk[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){FOR(i,0,9)bk[i]=0;ans=0;}
V work(){
	FOR(i,1,n)bk[a[i]%10]=1;
	FOR(i,1,n)FOR(j,1,i-1)if(a[i]==a[j])
		FOR(k,0,9)if(!bk[k]){
			bk[k]=1,a[i]-=a[i]%10,a[i]+=k,ans++;
			break;
	}
	printf("%d\n",ans);
	FOR(i,1,n)printf("%04d\n",a[i]);
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