#include<bits/stdc++.h>
using namespace std;
#define N 105
#define M 54
typedef long long ll;
typedef unsigned long long ull;
const ull inf=1uLL<<63;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,K;
struct ACM{
	int cnt;
	struct node{
		int ch[2],nxt,ban;
	}trie[M];
	ACM(){cnt=1;}
	void Insert(vector<int> s){
		int len=s.size();
		int u=1;
		for(int i=0;i<len;++i){
			int c=s[i];
			if(!trie[u].ch[c])trie[u].ch[c]=++cnt;
			u=trie[u].ch[c];
		}
		trie[u].ban=1;
	}
	void build(){
		queue<int> q;
		trie[0].ch[0]=trie[0].ch[1]=1;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<=1;++c){
				int v=trie[u].ch[c];
				if(v){
					trie[v].nxt=trie[trie[u].nxt].ch[c];
					q.push(v);
				}
				else trie[u].ch[c]=trie[trie[u].nxt].ch[c];
			}
			trie[u].ban|=trie[trie[u].nxt].ban;
		}
	}
}T;
ull dp[N][M][M];
int h[N];
vector<int> vec[N],G[N]; 
int main(){
	n=read(),K=read(),m=read();
	for(int i=1;i<=K;++i){
		h[i]=read();
		int z=read();
		while(z--){
			int x=read();
			G[i].push_back(x);
			vec[x].push_back(i);
		}
	}
	for(int i=0;i<n;++i){
		sort(vec[i].begin(),vec[i].end());
		vec[i].erase(unique(vec[i].begin(),vec[i].end()),vec[i].end());
	}
	for(int i=1;i<=m;++i){
		static vector<int> s;
		s.clear();
		int z=read();
		while(z--)s.push_back(read());
		T.Insert(s);
	}
	T.build();
	m=T.cnt;
	for(int i=0;i<n;++i)
		for(int j=1;j<=m;++j)
			for(int k=1;k<=m;++k)
				dp[i][j][k]=inf;
	queue<int> q;
	static int inq[N];
	for(int c=0;c<=1;++c){
		for(int u=1;u<=m;++u){
			int v=T.trie[u].ch[c];
			if(!T.trie[v].ban){
				dp[c][u][v]=1;
				if(!inq[c])q.push(c),inq[c]=1;
			}
		}	
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(auto t:vec[u]){
			static ull f[M][M];
			for(int u=1;u<=m;++u)
				for(int v=1;v<=m;++v)
					f[u][v]=(u==v?0:inf);
			for(auto j:G[t]){
				static ull g[M][M];
				for(int u=1;u<=m;++u)
					for(int v=1;v<=m;++v)
						g[u][v]=inf;	
				for(int u=1;u<=m;++u)
					for(int k=1;k<=m;++k)
						for(int v=1;v<=m;++v)
							if(f[u][k]<inf&&dp[j][k][v]<inf){
								g[u][v]=min(g[u][v],f[u][k]+dp[j][k][v]);
							}
				swap(f,g);
			}
			int i=h[t]; 
			for(int u=1;u<=m;++u){
				for(int v=1;v<=m;++v){
					if(f[u][v]<dp[i][u][v]){
						dp[i][u][v]=f[u][v];
						if(!inq[i])q.push(i),inq[i]=1;
					}
				}
			}
		} 
	}
	for(int i=2;i<n;++i){
		ull ans=inf;
		for(int j=1;j<=m;++j){
			ans=min(dp[i][1][j],ans);	
		}
		if(ans==inf){
			printf("YES\n");
		}
		else{
			printf("NO %llu\n",ans);
		}
	}
	return 0;
}