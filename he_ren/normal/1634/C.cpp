#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	if(k == 1)
	{
		printf("Yes\n");
		for(int i=1; i<=n; ++i) printf("%d\n",i);
		return;
	}
	
	if(n % 2)
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
		int tot = n * k;
		vector<int> a;
		for(int i=1; i<=tot; i+=2)
			a.push_back(i);
		for(int i=2; i<=tot; i+=2)
			a.push_back(i);
		for(int i=0; i<n*k; ++i)
		{
			printf("%d ",a[i]);
			if(i%k == k-1) printf("\n");
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}