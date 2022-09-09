#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

set<int> *t[MAXN];

int main(void)
{	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
		t[i] = new set<int>;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		t[x] -> insert(i);
	}
	
	int ans = n-1;
	for(int i=1; i<=m; ++i)
	{
		set<int> &cur = *t[i];
		int lst = -1;
		for(set<int>::iterator it = cur.begin(); it != cur.end(); ++it)
		{
			if(lst == *it - 1) --ans;
			lst = *it; 
		}
	}
	
	printf("%d\n",ans);
	
	for(int kk=1; kk<m; ++kk)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(t[u] -> size() < t[v] -> size()) swap(t[u], t[v]);
		set<int> &cur = *t[u], &oth = *t[v];
		
		set<int>::iterator it;
		for(it = oth.begin(); it != oth.end(); ++it)
		{
			if(cur.find(*it-1) != cur.end()) --ans;
			if(cur.find(*it+1) != cur.end()) --ans;
		}
		
		for(it = oth.begin(); it != oth.end(); ++it)
			cur.insert(*it);
		
		printf("%d\n",ans);
		
		delete t[v];
	}
	return 0;
}