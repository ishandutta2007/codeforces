#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

set<int> t[MAXN];

int ans;
inline bool chk(int u){ return !t[u].size() || *t[u].rbegin() < u;}
inline void add(int u,int v)
{
	ans -= chk(u);
	t[u].insert(v);
	ans += chk(u);
}
inline void del(int u,int v)
{
	ans -= chk(u);
	t[u].erase(v);
	ans += chk(u);
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	ans = n;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int oper;
		scanf("%d",&oper);
		if(oper == 3){ printf("%d\n",ans); continue;}
		int u,v;
		scanf("%d%d",&u,&v);
		if(oper == 1) add(u,v), add(v,u);
		else del(u,v), del(v,u);
	}
	return 0;
}