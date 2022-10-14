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
const int N=2e2+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int T,n,m,t[N][N];
char a[N][N];
struct node{
	int ax,ay,bx,by,cx,cy;
	V work(){t[ax][ay]^=1,t[bx][by]^=1,t[cx][cy]^=1;}
	V output(){
//		assert(max(max(ax,bx),cx)-min(min(ax,bx),cx)==1);
//		assert(max(max(ay,by),cy)-min(min(ay,by),cy)==1);
		cout<<ax<<' '<<ay<<' '<<bx<<' '<<by<<' '<<cx<<' '<<cy<<'\n';
	}
};
vector<node>ans;
V input(){
	scanf("%d%d",&n,&m),ans.clear();
	FOR(i,1,n)scanf("%s",a[i]+1);
	FOR(i,1,n)FOR(j,1,m)t[i][j]=a[i][j]-'0';
}
V init(){
	ROF(i,n,3)FOR(j,1,m)if(t[i][j]){
			if(j==1)ans.push_back((node){i,j,i-1,j,i-1,j+1}),ans.back().work();
			else ans.push_back((node){i,j,i-1,j,i-1,j-1}),ans.back().work();
		}
}
V work(){
	ROF(j,m,3){
		if(t[1][j]&&t[2][j])
			ans.push_back((node){1,j,2,j,1,j-1}),ans.back().work();
		if(t[1][j])ans.push_back((node){1,j,1,j-1,2,j-1}),ans.back().work();
		if(t[2][j])ans.push_back((node){2,j,1,j-1,2,j-1}),ans.back().work();
	}
	int cnt=0;
	FOR(i,1,2)FOR(j,1,2)cnt+=t[i][j];
	FOR(i,1,2)FOR(j,1,2)t[i][j]^=cnt&1;
	FOR(i,1,2)FOR(j,1,2)if(t[i][j]){
		ans.push_back((node){i%2+1,j%2+1,i%2+1,j,i,j%2+1}),t[i][j]^=1;
	}
	cout<<ans.size()<<'\n';
	for(node v:ans)v.output();
//	FOR(i,1,n)FOR(j,1,m)if(t[i][j])assert(!t[i][j]);
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