#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int inf = 0x3f3f3f3f;

int c[MAXN][MAXN];
int anc[MAXN * 2], val[MAXN * 2], pcnt;

inline void build_tree(vector<int> vec,int pre)
{
	int u = vec[0];
	val[u] = c[u][u];
	if((int)vec.size() == 1)
	{
		anc[u] = pre;
		return;
	}
	
	vector<pii> p(vec.size() - 1);
	for(int i=1; i<(int)vec.size(); ++i)
		p[i-1] = make_pair(c[u][vec[i]], vec[i]);
	sort(p.begin(), p.end());
	
	vector<int> nodes(1,u);
	for(int i=0,j=0; i<(int)p.size(); i=j)
	{
		while(j<(int)p.size() && p[i].first == p[j].first) ++j;
		
		if(p[i].first == val[pre]) nodes.push_back(pre);
		else nodes.push_back(++pcnt), val[pcnt] = p[i].first;
		
		vector<int> nxt;
		for(int k=i; k<j; ++k) nxt.push_back(p[k].second);
		build_tree(nxt, nodes.back());
	}
	if(nodes.back() != pre) nodes.push_back(pre);
	
	for(int i=0; i+1<(int)nodes.size(); ++i)
		anc[nodes[i]] = nodes[i+1];
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) scanf("%d",&c[i][j]);
	
	pcnt = n;
	vector<int> vec(n);
	for(int i=1; i<=n; ++i) vec[i-1] = i;
	val[0] = inf;
	build_tree(vec,0);
	
	printf("%d\n",pcnt);
	for(int i=1; i<=pcnt; ++i) printf("%d ",val[i]);
	putchar('\n');
	for(int i=1; i<=pcnt; ++i)
		if(!anc[i]){ printf("%d\n",i); break;}
	for(int i=1; i<=pcnt; ++i)
		if(anc[i]) printf("%d %d\n",i,anc[i]);
	return 0;
}