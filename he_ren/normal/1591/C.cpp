#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	vector<int> a,b;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		if(x > 0) a.push_back(x);
		if(x < 0) b.push_back(-x);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int mx = 0;
	ll sum = 0;
	for(int i=(int)a.size()-1; i>=0; i-=d)
		sum += a[i], mx = max(mx, a[i]);
	for(int i=(int)b.size()-1; i>=0; i-=d)
		sum += b[i], mx = max(mx, b[i]);
	
	printf("%lld\n",sum * 2 - mx);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}