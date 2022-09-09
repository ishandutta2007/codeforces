#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

int a[MAXN];
int f[MAXN], sumf[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	f[0] = sumf[0] = 1;
	static int sta[MAXN], val[MAXN], tp = 0;
	int sum = 0;
	for(int i=1; i<=n; ++i)
	{
		while(tp && a[sta[tp]] >= a[i])
		{
			sum = (sum - val[tp] + mod) %mod;
			--tp;
		}
		val[tp+1] = (ll)a[i] * (sumf[i-1] - (tp? sumf[sta[tp]-1]: 0) + mod) %mod;
		sta[++tp] = i;
		sum = (sum + val[tp]) %mod;
		
		f[i] = (mod - sum) %mod;
		sumf[i] = (sumf[i-1] + f[i]) %mod;
	}
	
	int ans = f[n];
	if(n&1) ans = (mod - ans) %mod;
	printf("%d",ans);
	return 0;
}