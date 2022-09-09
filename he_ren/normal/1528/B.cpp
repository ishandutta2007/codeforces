#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

int f[MAXN];
ll pw2[MAXN];

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; j+=i)
			++f[j];
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		ans = (ans + (ll)pw2[max(n - i - 1, 0)] * f[i]) %mod;
	
	printf("%d\n",ans);
	return 0;
}