#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int sum = 0;
	for(int i=1; i<=n; ++i)
		sum += a[i];
	
	for(int i=2; i<sum; ++i)
		if(sum % i == 0)
		{
			printf("%d\n",n);
			for(int j=1; j<=n; ++j)
				printf("%d ",j);
			printf("\n");
			return;
		}
	
	int mn = -1;
	for(int i=1; i<=n; ++i)
		if(a[i] & 1)
			if(mn == -1 || a[i] < a[mn])
				mn = i;
	
	printf("%d\n",n-1);
	for(int j=1; j<=n; ++j)
		if(j != mn) printf("%d ",j);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}