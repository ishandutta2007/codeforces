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
const int MAXN = 1e3 + 5;
const int MAXX = 20 + 5;
const int inf = 0x3f3f3f3f;

template<const char minc='0', const int MAXD = 10>
struct Aho_Corasick
{
	struct Node
	{
		int link[MAXD], suff;
		bool leaf;
		Node(void): suff(-1), leaf(0) { memset(link,-1,sizeof(link));}
	};
	
	vector<Node> p;
	
	Aho_Corasick(void){ p.resize(1);}
	Aho_Corasick(const vector<string> &vec){ p.resize(1); build(vec);}
	inline void clear(void){ p.resize(1);}
	
	inline int size(void){ return (int)p.size();}
	
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
		p[u].leaf = 1;
	}
	
	void build(void)
	{
		queue<int> q;
		p[0].suff = 0;
		q.push(0);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
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
	
	inline bool is_leaf(int u){ return p[u].leaf;}
	inline int link(int u, char c){ return p[u].link[c-minc];}
};

int x;

char a[MAXX];
inline bool check(int pos)
{
	for(int i=1; i<pos; ++i)
	{
		int sum = 0;
		for(int j=i; j<pos; ++j)
		{
			sum += a[j] - '0';
			if(sum<x && x%sum==0) return 0;
		}
	}
	return 1;
}

Aho_Corasick<'0',10> ac_auto;

void dfs(int sum,int pos)
{
	if(sum>x) return;
	if(sum == x){ if(check(pos)) ac_auto.insert(string(a+1,a+pos)); return;}
	
	for(int i=1; i<=9 && sum+i<=x; ++i)
		a[pos] = i + '0',
		dfs(sum+i, pos+1);
}

char s[MAXN];

int main(void)
{
	scanf("%s%d",s+1,&x);
	int n = strlen(s+1);
	
	dfs(0,1);
	ac_auto.build();
	
	int tot = ac_auto.size();
	
	vector<int> dp(tot, inf);
	dp[0] = 0;
	
	for(int i=1; i<=n; ++i)
	{
		vector<int> ndp(tot, inf);
		
		for(int j=0; j<tot; ++j) if(dp[j] != inf)
		{
			ndp[j] = min(ndp[j], dp[j] + 1);
			
			int k = ac_auto.link(j, s[i]);
			if(!ac_auto.is_leaf(k))
				ndp[k] = min(ndp[k], dp[j]);
		}
		
		dp = ndp;
	}
	
	printf("%d",*min_element(dp.begin(), dp.end()));
	return 0;
}