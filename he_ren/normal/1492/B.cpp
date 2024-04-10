#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int p[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	set<int> t;
	for(int i=1; i<=n; ++i) t.insert(i);
	
	int cur = n;
	while(t.size())
	{
		int need = *t.rbegin();
		
		int l = cur;
		while(p[l] != need) --l;
		
		for(int i=l; i<=cur; ++i) printf("%d ",p[i]), t.erase(p[i]);
		cur = l - 1;
	}
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}