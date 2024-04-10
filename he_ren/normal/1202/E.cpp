#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

template<const char minc,const int MAXD>
struct Aho_Corasick
{
	struct Node
	{
		int link[MAXD], suff, leaf;
		Node(): suff(-1), leaf(0) { memset(link,-1,sizeof(link));}
	};
	vector<Node> p;
	
	Aho_Corasick(void): p(1) {}
	
	void insert(const string &s)
	{
		int u = 0;
		for(int i=0; i<(int)s.size(); ++i)
		{
			if(p[u].link[s[i] - minc] == -1)
				p[u].link[s[i] - minc] = (int)p.size(),
				p.push_back(Node());
			u = p[u].link[s[i] - minc];
		}
		++p[u].leaf;
	}
	
	void build(void)
	{
		queue<int> q;
		p[0].suff = 0; q.push(0);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			if(u) p[u].leaf += p[p[u].suff].leaf;
			for(int i=0; i<MAXD; ++i)
			{
				int &v = p[u].link[i];
				if(~v)
					p[v].suff = u? p[p[u].suff].link[i]: 0,
					q.push(v);
				else v = u? p[p[u].suff].link[i]: 0;
			}
		}
	}
	void build(const vector<string> &vec)
	{
		for(int i=0; i<(int)vec.size(); ++i)
			insert(vec[i]);
		build();
	}
	
	inline int link(int u,char c){ return p[u].link[c-minc];}
	inline int leaf(int u){ return p[u].leaf;}
};

char t[MAXM];
string s[MAXN];

int main(void)
{
	int n;
	scanf("%s%d",t+1,&n);
	int m = strlen(t+1);
	for(int i=1; i<=n; ++i)
		cin>>s[i];
	
	static Aho_Corasick<'a',26> pre, suf;
	
	for(int i=1; i<=n; ++i)
	{
		pre.insert(s[i]);
		reverse(s[i].begin(), s[i].end());
		suf.insert(s[i]);
	}
	pre.build(); suf.build();
	
	static int f[MAXN], g[MAXN];
	
	int u = 0;
	for(int i=1; i<=m; ++i)
	{
		u = pre.link(u, t[i]);
		f[i] = pre.leaf(u);
	}
	
	u = 0;
	for(int i=m; i>=1; --i)
	{
		u = suf.link(u, t[i]);
		g[i] = suf.leaf(u);
	}
	
	ll ans = 0;
	for(int i=1; i<m; ++i)
		ans += (ll)f[i] * g[i+1];
	printf("%lld\n",ans);
	return 0;
}