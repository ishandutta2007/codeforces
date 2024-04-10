#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 500050
typedef long long ll;
int n,Q;
class BIT{
	int b[N],Len;
	inline int lowbit(int x){return x&(-x);}
public:
	void init(int _n){Len=_n;}
	inline void Add(int x,int d){
		while(x<=Len)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
class ACAM{
public:
	int tot,num;
	struct node{
		int ch[26],fa,nxt;
	}t[N];
	ACAM(){tot=1;}
	vector<int> G[N];
	int siz[N],dfn[N];
	int Insert(const string &s){
		int u=1;
		for(auto _c:s){
			int c=_c-'a';
			if(!t[u].ch[c])t[u].ch[c]=++tot;
			u=t[u].ch[c];
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
		for(int i=0;i<26;++i){
			t[0].ch[i]=1;
		}
		q.push(1);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int c=0;c<26;++c){
				int v=t[u].ch[c];
				if(v){
					t[v].nxt=t[t[u].nxt].ch[c];
					q.push(v);
				}
				else{
					t[u].ch[c]=t[t[u].nxt].ch[c];
				}
			}
		}
		for(int i=2;i<=tot;++i){
			G[t[i].nxt].push_back(i);
		}
		dfs(1);
	}
}T;
vector<pair<int,int> > q[N];
int ans[M],g[N];
string s[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		g[i]=T.Insert(s[i]);
	}
	T.build();
	for(int i=1;i<=Q;++i){
		int l,r,k;
		cin>>l>>r>>k;
		q[r].emplace_back(k,i);
		q[l-1].emplace_back(k,-i);
	}
	B.init(T.tot);
	for(int i=1;i<=n;++i){
		for(int j=0,u=1;j<(int)s[i].length();++j){
			int c=s[i][j]-'a';
			u=T.t[u].ch[c];
			B.Add(T.dfn[u],1);
		}
		for(auto [j,id]:q[i]){
			ans[abs(id)]+=(id>0?1:-1)*(B.Ask(T.dfn[g[j]]+T.siz[g[j]]-1)-B.Ask(T.dfn[g[j]]-1));
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}