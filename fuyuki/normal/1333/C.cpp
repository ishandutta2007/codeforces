#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
int n,a[N];
ll s[N],ans;
set<ll>mp;
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V work(){
	int p=0;
	mp.insert(0);
	FOR(i,1,n){
		s[i]=s[i-1]+a[i];
		while(mp.find(s[i])!=mp.end())
			mp.erase(s[p++]);
		mp.insert(s[i]);
		ans+=i-p;
	}
	cout<<ans;
}
int main(){
	input();
	work();
	return 0;
}