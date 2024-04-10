#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 400005
int n,d[maxn];
struct edge{
	int to,nxt;
}e[maxn<<1];
int tot=1,head[maxn];
inline void adde(int u,int v){
	e[++tot]=(edge){v,head[u]};
	head[u]=tot;
}

int vis[maxn];
void dfs(int u)
{
	for(int&i=head[u];i;i=e[i].nxt)
		if(!vis[i>>1]){
			vis[i>>1]=(u<=200000)+1;
			dfs(e[i].to);
		}
}

signed main()
{
	n=read();
	For(i,1,n){
		int x=read(),y=read()+200000;
		adde(x,y),adde(y,x),d[x]++,d[y]++;
	}
	For(i,1,400000)
		if(d[i]&1)adde(0,i),adde(i,0);
	For(i,1,400000)dfs(i);
	For(i,1,n)putchar("br"[vis[i]-1]);
	return 0;
}