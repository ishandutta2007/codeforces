#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 40 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int res = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(a[j] > a[i])
			res = gcd(res, a[j] - a[i]);
	printf("%d\n",res == 0? -1: res);
}


int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}