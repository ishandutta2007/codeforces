#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
string t;
int n;
ll ans;
class SAM{
public:
	int tot,las,p[N];
	SAM(){tot=las=1;}
	struct node{
		int ch[26],fa,len;
	}t[N];
	vector<int> G[N];
	int dfn[N],num;
	int siz[N],son[N],top[N],dep[N],f[N],id[N];
	void Insert(int c){
		int p=las,u=++tot;
		t[u].len=t[p].len+1;
		while(p&&!t[p].ch[c]){
			t[p].ch[c]=u;
			p=t[p].fa;
		}
		if(!p)t[u].fa=1;
		else{
			int q=t[p].ch[c];
			if(t[q].len==t[p].len+1){
				t[u].fa=q;
			}
			else{
				int v=++tot;
				t[v]=t[q],t[v].len=t[p].len+1;
				while(p&&t[p].ch[c]==q){
					t[p].ch[c]=v;
					p=t[p].fa;
				}
				t[u].fa=t[q].fa=v;
			}
		}
		las=u;
	}
	void dfs1(int u){
		dfn[u]=++num;
		id[num]=u;
		siz[u]=1;
		for(auto v:G[u]){
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]){
				son[u]=v;
			}
		}
	}
	void dfs2(int u,int topf){
		top[u]=topf;
		if(!son[u])return;
		dfs2(son[u],topf);
		for(auto v:G[u]){
			if(v==son[u])continue;
			dfs2(v,v);
		}
	}
	inline int LCA(int u,int v){
		while(top[u]^top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			u=f[top[u]];
		}
		if(dep[u]>dep[v])swap(u,v);
		return u;
	}
	inline int Dis(int u,int v){
		return t[u].len+t[v].len-(t[LCA(u,v)].len<<1);	
	}
	void build(const string &s){
		las=1;
		for(int i=0;i<(int)s.length();++i){
			int c=s[i]-'a';
			Insert(c);
			p[i]=las;
			if(i<(int)s.length()-1)ans+=t[las].len-t[t[las].fa].len;
		}
		for(int i=2;i<=tot;++i){
			G[f[i]=t[i].fa].push_back(i);
		}
		dfs1(1);
		dfs2(1,1);
	}	
}A,B;
set<int> s[N];
ll len[N];
int qwq;
void dfs(int u){
	for(auto v:A.G[u]){
		dfs(v);
		if(s[v].size()>s[u].size()){
			swap(s[u],s[v]);
			swap(len[u],len[v]);
		}
		for(auto x:s[v]){
			if(s[u].count(x))continue;
			s[u].insert(x);
			if(s[u].size()==1)continue;
			auto it=s[u].lower_bound(x);
			bool flag=false;
			int L=it==s[u].begin()?*--s[u].end():(flag=true,*--it);
			if(flag)++it;
			++it;
			int R=it==s[u].end()?*s[u].begin():*it;
			++qwq;
			len[u]+=(B.Dis(B.id[x],B.id[L])+B.Dis(B.id[x],B.id[R])-B.Dis(B.id[L],B.id[R]))/2;
		}
	}
	ans+=1LL*len[u]*(A.t[u].len-A.t[A.t[u].fa].len);
}
void Solve(){
	cin>>t;
	n=t.length();
	A.build(t);
	reverse(t.begin(),t.end());
	B.build(t);
	for(int i=0;i<n-2;++i){
		s[A.p[i]].insert(B.dfn[B.p[n-i-3]]);
		s[A.p[i]].insert(1);
		len[A.p[i]]=B.t[B.p[n-i-3]].len;
	}
	ans+=2;
	for(int i=1;i<=A.tot;++i){
		ans+=A.t[i].len-A.t[A.t[i].fa].len;
	}
	dfs(1);
	printf("%lld\n",ans);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}