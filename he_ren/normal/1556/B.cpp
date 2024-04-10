#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];

inline ll calc(vector<int> &p,vector<int> &q)
{
	if((int)p.size() != (int)q.size()) return linf;
	ll res = 0;
	for(int i=0; i<(int)p.size(); ++i)
		res += abs(p[i] - q[i]);
	return res;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]), a[i] %= 2;
	
	static vector<int> pos[2], vec[2];
	for(int i=0; i<=1; ++i) pos[i] = vec[i] = vector<int>();
	
	for(int i=1; i<=n; ++i)
		pos[a[i]].push_back(i), vec[i&1].push_back(i);
	
	ll ans = min(calc(pos[0], vec[0]), calc(pos[0], vec[1]));
	
	if(ans >= linf) printf("-1\n");
	else printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}