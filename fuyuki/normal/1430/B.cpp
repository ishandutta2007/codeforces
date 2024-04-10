#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
ll sum;
int T,n,k,a[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	sort(a+1,a+1+n);
}
V work(){
	if(k==0)cout<<a[n]-a[1]<<'\n';
	else{
		ROF(i,n,n-k)sum+=a[i];
		cout<<sum<<'\n',sum=0;
	}
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