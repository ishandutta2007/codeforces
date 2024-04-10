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
#define P pair<int,int>
const int N=1e3+5,INF=0x3f3f3f3f;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,q,f[N][N];
char a[N][N];
queue<P>Q;
V input(){
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>a[i]+1;
}
I find(int x,int y,char c){
	FOR(i,0,3){
		int tx=x+dx[i],ty=y+dy[i];
		if(a[tx][ty]==c)return 1;
	}
	return 0;
}
V init(){
	FOR(i,1,n)FOR(j,1,m)
		if(find(i,j,a[i][j]))
			f[i][j]=0,Q.push(P(i,j));
		else f[i][j]=INF;
	P now;
	int x,y,tx,ty;
	while(!Q.empty()){
		now=Q.front(),Q.pop();
		x=now.first,y=now.second;
		FOR(i,0,3){
			tx=x+dx[i],ty=y+dy[i];
			if(f[x][y]+1<f[tx][ty])
				f[tx][ty]=f[x][y]+1,Q.push(P(tx,ty));
		}
	}
}
V work(){
	int x,y;ll w;
	while(q--){
		cin>>x>>y>>w;
		if(f[x][y]==INF)cout<<a[x][y]<<'\n';
		else if(w<=f[x][y])cout<<a[x][y]<<'\n';
		else if(w-f[x][y]&1)cout<<(char)(a[x][y]^1)<<'\n';
		else cout<<a[x][y]<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}