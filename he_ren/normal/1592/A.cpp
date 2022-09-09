#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN];

void solve(void)
{
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	int x = a[n], y = a[n-1];
	int k = h / (x + y);
	h -= k * (x + y);
	if(h == 0) printf("%d\n",k * 2);
	else if(h <= x) printf("%d\n",k * 2 + 1);
	else printf("%d\n",k * 2 + 2);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}