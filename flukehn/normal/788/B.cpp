#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;i--)
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int MX=1e6+11;
struct Edge{int v;Edge*nxt;}pl[MX<<2],*cur=pl,*G[MX];
inline void ins(int u,int v){*cur=(Edge){v,G[u]},G[u]=cur++;}
int n,m,d[MX];
int q[MX];
bool vis[MX];
int bfs(int S){
	memset(vis,0,sizeof vis);
	int h=0,t=0;
	vis[q[t++]=S]=1;
	while(h<t){
		int x=q[h++];
		for(Edge *i=G[x];i;i=i->nxt){
			if(!vis[i->v]) {
				vis[i->v]=1;
				q[t++]=i->v;
			}
		}
	}
	return t;
}
int main(){
	n=rd(),m=rd();
	int tot=0;
	rep(i,1,m){
		int u=rd(),v=rd();
		vis[u]=vis[v]=1;
		if(u!=v){
			d[u]++,d[v]++;
			ins(u,v);
			ins(v,u);
		} else tot++;
	}
	int q=n,o;rep(i,1,n)if(!vis[i])q--;
	rep(i,1,n)if(vis[i]){o=i;break;}
	if(bfs(o)!=q||m<2) puts("0");
	else {
		ll ans=1LL*tot*(tot-1)/2+1LL*tot*(m-tot);
		rep(i,1,n) {
			ans+=1LL*d[i]*(d[i]-1)/2;
		}
		cout<<ans<<endl;
	} 
}