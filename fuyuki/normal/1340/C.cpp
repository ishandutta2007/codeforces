#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(int deg=10){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*deg+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e4+3,M=1e3+1,INF=0x7fffffff;
int T,n,m,g,r,ans,cnt;
int d[N],f[N][M];
V input(){
	n=getint(),m=getint();
	FOR(i,1,m)d[i]=getint();
	g=getint(),r=getint();
}
V init(){
	sort(d+1,d+1+m),m=unique(d+1,d+1+m)-d-1,ans=INF;
	FOR(i,1,m)FOR(j,0,g)f[i][j]=INF;
}
vector<int>a[M],tmp;
V work(){
	if(d[1]<=g)f[1][d[1]]=d[1],a[d[1]].push_back(1);
	int dis;
	do{
		FOR(i,0,g){
			for(int x:a[i]){
				if(x!=1){
					dis=d[x]-d[x-1];
					if(i+dis<=g&&f[x-1][i+dis]>f[x][i]+dis)
						f[x-1][i+dis]=f[x][i]+dis,a[i+dis].push_back(x-1);
				}
				if(x!=m){
					dis=d[x+1]-d[x];
					if(i+dis<=g&&f[x+1][i+dis]>f[x][i]+dis)
						f[x+1][i+dis]=f[x][i]+dis,a[i+dis].push_back(x+1);
				}
				if(i==g){
					if(f[x][0]>f[x][i]+r)
						f[x][0]=f[x][i]+r,tmp.push_back(x);
				}
				dis=n-d[x];
				if(i+dis<=g)ans=min(ans,f[x][i]+dis);
			}
			a[i].clear();
		}
		a[0]=tmp,tmp.clear();
	}while(!a[0].empty());
	if(ans==INF)
		cout<<"-1";
	else cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}