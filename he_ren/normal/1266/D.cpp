#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

ll out[MAXN], in[MAXN];

vector< pair<pii,ll> > ans;
inline void push_ans(int u,int v,ll w){ ans.push_back(make_pair(make_pair(u,v),w));}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		out[u] += w; in[v] += w;
	}
	
	queue<int> q1,q2;
	for(int i=1; i<=n; ++i)
	{
		ll mn = min(out[i], in[i]);
		out[i] -= mn; in[i] -= mn;
		if(out[i]) q1.push(i);
		if(in[i]) q2.push(i);
	}
	
	while(q1.size() && q2.size())
	{
		int u = q1.front(), v = q2.front();
		ll w = min(out[u], in[v]);
		push_ans(u,v,w);
		out[u] -= w; in[v] -= w;
		if(!out[u]) q1.pop();
		if(!in[v]) q2.pop();
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d %lld\n",ans[i].first.first,ans[i].first.second,ans[i].second);
	return 0;
}