#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+1,INF=0x3f3f3f3f;
int n,ans;
vector<int>e[N];
V add_edge(int x,int y){e[x].push_back(y),e[y].push_back(x);}
V dfs(int u,int fa=0,int d=0){ans+=d;for(int v:e[u])if(v^fa)dfs(v,u,d^1);}
int main(){
	n=getint();
	FOR(i,2,n)add_edge(getint(),getint());
	dfs(1),cout<<min(ans,n-ans)-1;
	return 0;
}