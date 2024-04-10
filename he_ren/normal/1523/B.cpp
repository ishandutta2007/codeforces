#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	printf("%d\n",6 * n / 2);
	for(int i=1; i<=n; i+=2)
	{
		int j = i + 1;
		for(int k=1; k<=6; ++k)
			printf("%d %d %d\n",(k&1) == (k<=3)? 2: 1,i,j);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}