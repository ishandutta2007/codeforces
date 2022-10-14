#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define I inline int
#define V inline void
#define ld long double
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
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int INF=0x7fffffff,N=1e6+1;
int n,top,cnt[N];
ld a[N],val[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V work(){
	ld sum=0;int len=0;
	ROF(i,n,1){
		sum=a[i],len=1;
		while(top&&(sum+val[top]*cnt[top])/(len+cnt[top])<sum/len)
			sum+=val[top]*cnt[top],len+=cnt[top],top--;
		val[++top]=sum/len,cnt[top]=len;
	}
	while(top){
		FOR(i,1,cnt[top])printf("%.9lf\n",(double)val[top]);
		top--;
	}
}
int main(){
	input();
	work();
	return 0;
}