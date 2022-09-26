#include<bits/stdc++.h>
using namespace std;
#define N 2000010
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
int n,Q;
char s[N];
struct SAM{
	int las,tot,d[N];
	SAM(){las=tot=1;}
	struct node{
		int ch[26],fa,len;
	}t[N];
	void Insert(int c){
		int u=++tot,p=las;
		t[u].len=t[p].len+1;
		++d[u];
		while(p&&!t[p].ch[c]){
			t[p].ch[c]=u,p=t[p].fa;
		}
		if(!p)t[u].fa=1;
		else{
			int q=t[p].ch[c];
			if(t[q].len==t[p].len+1)t[u].fa=q;
			else{
				int v=++tot;
				t[v]=t[q],t[v].len=t[p].len+1;
				while(p&&t[p].ch[c]==q){
					t[p].ch[c]=v,p=t[p].fa;
				}
				t[u].fa=t[q].fa=v;
			}
		}
		las=u;
	}
	vector<int> G[N];
	void dfs(int u){
		for(auto v:G[u])dfs(v),d[u]+=d[v];
	}
	void build(char *s,int n){
		for(int i=1;i<=n;++i){
			Insert(s[i]-'a');
		}
		for(int i=2;i<=tot;++i){
			G[t[i].fa].push_back(i);
		}
		dfs(1);
	}
	ll Query(char *s){
		static int myh,vis[N];
		++myh;
		int n=strlen(s+1);
		int u=1;
		ll ans=0;
		for(int i=1,len=0;i<=n+n;++i){
			int c=s[i>n?i-n:i]-'a';
			while(u&&!t[u].ch[c])u=t[u].fa,len=t[u].len;
			if(!u)break;
			u=t[u].ch[c];++len;
			if(len>=n){
				while(t[t[u].fa].len>=n)u=t[u].fa;
				if(vis[u]^myh)ans+=d[u],vis[u]=myh;
				len=n;
			}
		}
		return ans;
	}
}T;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	T.build(s,n);
	Q=read();
	while(Q--){
		scanf("%s",s+1);
		printf("%lld\n",T.Query(s));
	}
	return 0;
}