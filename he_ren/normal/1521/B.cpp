#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

vector< pair<pii,pii> > ans;
inline void push_ans(int i,int j,int x,int y){ ans.push_back(make_pair(make_pair(i,j), make_pair(x,y)));}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	const int mod = 1e9 + 7;
	
	ans.clear();
	for(int i=1; i<n; i+=2)
		push_ans(i, i+1, min(a[i], a[i+1]), mod);
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}