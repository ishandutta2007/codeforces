#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	vector<int> a(n);
	for(int i=0; i<n; ++i) scanf("%d",&a[i]);
	
	sort(a.begin(), a.end());
	map<int,int> t;
	int ans = n;
	for(int i=0; i<(int)a.size(); ++i)
	{
		if(a[i] % x == 0 && t.find(a[i] / x) != t.end() && t[a[i] / x])
			--t[a[i] / x], ans -= 2;
		else
			++t[a[i]];
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}