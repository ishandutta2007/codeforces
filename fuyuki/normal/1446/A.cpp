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
ll getint(){
	ll _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
ll W;
int T,n,a[N];
V input(){
	n=getint(),W=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
V work(){
	ll sum=0,w=(W+1)/2;
	vector<int>tmp;
	FOR(i,1,n){
		if(a[i]>W)continue;
		if(a[i]>=w)return void(cout<<1<<'\n'<<i<<'\n');
		sum+=a[i],tmp.push_back(i);
		if(sum>=w){
			cout<<tmp.size()<<'\n';
			for(int v:tmp)cout<<v<<' ';
			cout<<'\n';
			return;
		}
	}
	cout<<"-1\n";
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}