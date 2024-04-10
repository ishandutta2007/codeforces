#include<bits/stdc++.h>
using namespace std;
#define N 400010
typedef long long ll;
int n,m,ans[N];
vector<pair<int,int> > H[N],q[N];
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);};
public:
	inline void Add(int x,int d){
		while(x<N)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
class ACAM{
public:
	vector<int> G[N];
	int dfn[N],siz[N],num;
	int cnt;
	struct node{
		int ch[26],nxt;
	}trie[N];
	ACAM(){cnt=1;}
	int Insert(const string &s){
		int u=1;
		for(int i=0;i<(int)s.length();++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++cnt;
			u=trie[u].ch[c];
		}
		return u;
	}
	void dfs(int u){
		dfn[u]=++num;
		siz[u]=1;
		for(auto v:G[u]){
			dfs(v);
			siz[u]+=siz[v];
		}
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;++i)trie[0].ch[i]=1;
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<26;++c){
				int v=trie[u].ch[c];
				if(v){
					trie[v].nxt=trie[trie[u].nxt].ch[c];
					q.push(v);
				}
				else trie[u].ch[c]=trie[trie[u].nxt].ch[c];
			}
		}
		for(int i=2;i<=cnt;++i){
			G[trie[i].nxt].push_back(i);
		}
		dfs(1);
	}
	void Plus(int u,int d){
		if(u)B.Add(dfn[u],d);
	}
	int Ask(int u){
		return B.Ask(dfn[u]+siz[u]-1)-B.Ask(dfn[u]-1);
	}
}T;
void dfs(int u,int t){
	T.Plus(t,1);
	for(auto [id,z]:q[u]){
		ans[id]=T.Ask(z);
	}
	for(auto [v,c]:H[u]){
		dfs(v,T.trie[t].ch[c]);
	}
	T.Plus(t,-1);
}
void Solve(){
	cin>>n;
	for(int i=1,opt,fa;i<=n;++i){
		cin>>opt;
		if(opt==2)cin>>fa;
		else fa=0;
		char c;
		cin>>c;
		H[fa].emplace_back(i,c-'a');
	}
	cin>>m;
	for(int i=1,x;i<=m;++i){
		string t;
		cin>>x>>t;
		q[x].emplace_back(i,T.Insert(t));
	}
	T.build();
	dfs(0,1);
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}