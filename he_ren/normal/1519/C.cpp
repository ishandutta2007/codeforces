#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int p[MAXN], q[MAXN];

vector<ll> a[MAXN];
ll f[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) a[i].resize(1);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&q[i]);
	for(int i=1; i<=n; ++i) a[p[i]].push_back(q[i]);
	
	for(int i=1; i<=n; ++i) f[i] = 0;
	for(int k=1; k<=n; ++k)
	{
		vector<ll> &vec = a[k];
		sort(vec.begin()+1, vec.end());
		reverse(vec.begin()+1, vec.end());
		for(int i=1; i<(int)vec.size(); ++i) vec[i] += vec[i-1];
		
		int tot = (int)vec.size() - 1;
		for(int i=1; i<=tot; ++i)
			f[i] += vec[tot - tot % i];
	}
	
	for(int i=1; i<=n; ++i) printf("%lld ",f[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}