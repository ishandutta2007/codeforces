#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}


int n;
#define Maxn 100010
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int a[Maxn][2];
ll dp[Maxn][2];
void dfs(int u,int f){
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			dfs(v[i],u);
			int t=v[i];
			rep(j,0,1){
				dp[u][j]+=max(dp[v[i]][j]+abs(a[t][j]-a[u][j]),dp[t][j^1]+abs(a[t][j^1]-a[u][j]));
			}
		}
}

int main(){
	int T;
	rd(T);
	while(T--){
	rd(n);tot=0;
	memset(head,0,sizeof(int)*(n+1));
	int s,e;
	rep(i,1,n){
		rd(a[i][0]);rd(a[i][1]);
		dp[i][0]=dp[i][1]=0;
}
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}