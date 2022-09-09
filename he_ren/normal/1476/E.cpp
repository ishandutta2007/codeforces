#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MAXE = MAXM * 17;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

struct Edge
{
	int next,to;
}e[MAXE];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot; ++deg[v];
}

string s[MAXN], t[MAXM];
int need[MAXM];

int sid[200];
inline ll get_val(const string &s)
{
	ll cur = 0;
	for(int i=0; i<(int)s.size(); ++i) cur = cur * 28 + sid[(int)s[i]];
	return cur;
}

int main(void)
{
	for(int i=0; i<26; ++i) sid[i + 'a'] = i;
	sid[(int)'_'] = 27;
	
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) cin >> s[i];
	for(int i=1; i<=m; ++i) cin >> t[i] >> need[i];
	
	map<ll,int> pos;
	for(int i=1; i<=n; ++i)
		pos[get_val(s[i])] = i;
	
	int all = (1<<d) - 1;
	for(int i=1; i<=m; ++i)
	{
		bool has = 0;
		for(int mask=0; mask<=all; ++mask)
		{
			string tt = t[i];
			for(int j=0; j<d; ++j) if(bdig(mask,j))
				tt[j] = '_';
			ll val = get_val(tt);
			
			if(pos.find(val) == pos.end()) continue;
			int v = pos[val];
			
			if(v == need[i]) has = i;
			else add(need[i], v);
		}
		if(!has) return printf("NO"), 0;
	}
	
	queue<int> q;
	for(int i=1; i<=n; ++i) if(!deg[i]) q.push(i);
	vector<int> ans;
	while(q.size())
	{
		int u = q.front(); q.pop();
		ans.push_back(u);
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			--deg[v];
			if(!deg[v]) q.push(v);
		}
	}
	
	for(int i=1; i<=n; ++i) if(deg[i]) return printf("NO"), 0;
	printf("YES\n");
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	return 0;
}