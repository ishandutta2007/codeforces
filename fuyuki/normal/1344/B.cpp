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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=1e3+5;
//int T,n,a[N],b[N],*t;
int n,m,s[N][N];
char a[N][N];
int fa[N*N];
I id(int x,int y){
	return (x-1)*m+y;
}
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n)scanf("%s",a[i]+1);
}
V init(){
	int x=n,y=m;
	FOR(i,1,n){
		int flag=0;
		FOR(j,1,m)
			if(a[i][j]=='#'&&a[i][j-1]=='.'&&flag)
				cout<<"-1",exit(0);
			else flag|=a[i][j]=='#';
		x-=flag;
	}
	FOR(i,1,m){
		int flag=0;
		FOR(j,1,n)
			if(a[j][i]=='#'&&a[j-1][i]=='.'&&flag)
				cout<<"-1",exit(0);
			else flag|=a[j][i]=='#';
		y-=flag;
	}
	if((!x)^(!y))cout<<"-1",exit(0);
}
const int dx[4]={0,0,1,-1},dy[]={1,-1,0,0};
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
I merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	return fa[x]=y,1;
}
V work(){
	FOR(i,1,n)FOR(j,1,m)fa[id(i,j)]=id(i,j);//,cout<<id(i,j)<<" \n"[j==m];
	int ans=0,x,y;
	FOR(i,1,n)FOR(j,1,m)if(a[i][j]=='#'){
		ans++;
		FOR(k,0,3)if(a[x=i+dx[k]][y=j+dy[k]]=='#')
			ans-=merge(id(i,j),id(x,y));
	}
	cout<<ans;
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