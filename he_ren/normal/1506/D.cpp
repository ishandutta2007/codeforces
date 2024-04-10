#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	scanf("%d",&n);
	map<int,int> t;
	for(int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		++t[x];
	}
	
	int mx = 0;
	for(map<int,int>::iterator it = t.begin(); it != t.end(); ++it)
		mx = max(mx, it -> second);
	
	if(mx > n / 2) printf("%d\n",mx - (n - mx));
	else printf("%d\n",n % 2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}