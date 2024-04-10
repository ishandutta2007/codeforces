#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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

int n,K;
#define Maxn 200010
vector<int> vec[Maxn];
int siz[Maxn];

pii seq[Maxn];int cnt;int d[Maxn];
int fa[Maxn];
void dfs(int u,int f){
	for(int i=0;i<vec[u].size();++i)
		if(vec[u][i]!=f){
			int to=vec[u][i];
			d[to]=d[u]+1;
			fa[to]=u;
			dfs(to,u);
			siz[u]+=siz[to];
		}
	siz[u]++;
	seq[++cnt]=pii(siz[u],u);
}

ll Ans=0;

bool vis[Maxn];

void gao(int u,int f,int c){
	c+=vis[u];
	if(!vis[u])Ans+=c;
	 for(int i=0;i<vec[u].size();++i)
		if(vec[u][i]!=f){
			int to=vec[u][i];
			fa[to]=u;
			gao(to,u,c);
		}
}

priority_queue<pii> Q;

int main(){
	rd(n);rd(K);K=n-K;
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		vec[s].push_back(e);
		vec[e].push_back(s);
	}
	dfs(1,0); 
	Q.push(pii(n-1,1));
	rep(T,1,K){
		pii cur=Q.top();Q.pop();
		Ans+=cur.FR;
		int u=cur.SE;
		for(int i=0;i<vec[u].size();++i){
			int to=vec[u][i];
			if(to==fa[u])continue;
			Q.push(pii(siz[to]-1-d[to],to));
		}
	}
	printf("%lld\n",Ans);
	return 0;
}