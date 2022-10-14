#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1;
int n,ans;
char a[N];
V input(){scanf("%d %s",&n,a+1);}
V init(){
}
I max(const int&x,const int&y){return x>y?x:y;}
V work(){
	ans=0;rnt op=0,ed=0;
	FOR(i,1,n)if(a[i]=='1'){
		op=i;break;
	}
	ROF(i,n,1)if(a[i]=='1'){
		ed=i;break;
	}
//	if(op==ed)return void(cout<<n+!!op<<'\n');
	if(op==ed&&op==0)return void(cout<<n<<'\n');
	ans=max(ed*2,(n-op+1)*2);
	cout<<ans<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}