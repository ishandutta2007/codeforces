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
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
vector<int>ans;
int T,n,mod,a[N];
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V input(){
	n=getint(),mod=getint();
	FOR(i,1,n)a[i]=getint();
	sort(a+1,a+1+n);
}
I check(int x){
	int s=1;
	FOR(i,1,n)
		if(min(n,n-a[i]+x)-(n-i)<=0)
			return 0;
		else
			s=1ll*s*(min(n,n-a[i]+x)-(n-i))%mod;
	return s;
}
V init(){
	FOR(i,1,3000)if(check(i))
		ans.push_back(i);
	cout<<ans.size()<<'\n';
	for(int x:ans)cout<<x<<' ';
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	for(cin.tie(0),cin>>T;T--;){
		input();
		init();
		work();
//	}
	return 0;
}