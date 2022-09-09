#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<int> p;
	for(int i=1; i<n; ++i)
		if(a[i] == a[i+1]) p.push_back(i);
	
	if(p.size() <= 1) printf("0\n");
	else printf("%d\n",max(1, p.back() - p[0] - 1));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}