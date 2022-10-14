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
const int N=3e5+2,INF=0x3f3f3f3f;
vector<int>tmp;
int T,n,ans,a[N];
ll cnt[31][2],sum;
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
V solve(vector<int>t,int p){
	if(p==-1||t.empty())return;
	vector<int>lc,rc;
	int c0=0,c1=0;
	for(int x:t)
		if(x>>p&1)lc.push_back(x),c1++,cnt[p][1]+=c0;
		else rc.push_back(x),c0++,cnt[p][0]+=c1;
	solve(lc,p-1),solve(rc,p-1);
}
V work(){
	FOR(i,1,n)tmp.push_back(a[i]);
	solve(tmp,30);
	FOR(i,0,30)
		if(cnt[i][0]<=cnt[i][1])sum+=cnt[i][0];
		else ans|=1<<i,sum+=cnt[i][1];
	cout<<sum<<' '<<ans;
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}