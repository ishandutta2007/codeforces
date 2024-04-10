#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
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
int n,pos[N],ans;
string s[N];
vector<int> G[N];
struct ACAM{
	int cnt;
	ACAM(){cnt=1;}
	struct node{
		int ch[26],nxt,ed;	
	}trie[N];
	void Insert(string &s,int id){
		int len=s.length();
		int u=1;
		for(int i=0;i<len;++i){
			int c=s[i]-'a';
			if(!trie[u].ch[c])trie[u].ch[c]=++cnt;
			u=trie[u].ch[c];
		}
		trie[u].ed=id;
		pos[id]=u;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<26;++i){
			trie[0].ch[i]=1;	
		}	
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
			if(!trie[u].ed)trie[u].ed=trie[trie[u].nxt].ed;
			if(trie[u].nxt)G[trie[u].nxt].push_back(u);
		}
	}
}T;
struct BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=T.cnt)b[x]+=d,x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
int dfn[N],num,siz[N];
void dfs(int u){
	dfn[u]=++num;
	siz[u]=1;
	for(auto v:G[u]){
		dfs(v);
		siz[u]+=siz[v];
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s[i];
		T.Insert(s[i],i);
	}
	T.build();
	dfs(1);
	for(int i=1;i<=n;++i){
		int u=1;
		static vector<int> vec,zyk;
		static int buc[N];
		vec.clear();
		zyk.clear();
		for(int j=0;j<(int)s[i].length();++j){
			int c=s[i][j]-'a';
			u=T.trie[u].ch[c];
			vec.push_back(u); 
			B.Add(dfn[u],1);
		}
		int pre=1e9;
		for(int j=(int)vec.size()-1;j>=0;--j){
			int u=vec[j];
			int x=(j==(int)vec.size()-1?T.trie[T.trie[u].nxt].ed:T.trie[u].ed);
			if(!x)continue;
			int l=j-(int)s[x].length();
			if(l<pre)pre=l,++buc[x],zyk.push_back(x);
		}
		for(auto x:zyk){
			if(!buc[x])continue;
			int u=pos[x];
			if(B.Ask(dfn[u]+siz[u]-1)-B.Ask(dfn[u]-1)==buc[x])++ans;
			buc[x]=0;
		}
		for(auto u:vec)B.Add(dfn[u],-1);
	}
	printf("%d\n",ans);
	return 0;
}