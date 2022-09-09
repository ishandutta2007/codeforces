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
	a[n+1] = 0;
	
	if(accumulate(a+1,a+n+1,0) % 2 == 1 || *min_element(a+1,a+n+1) == 1)
	{
		printf("NO\n");
		return;
	}
	
	vector<int> ans;
	auto push_ans = [&] (int k)
	{
		if(k >= 1 && k <= n-2)
		{
			ans.push_back(k);
			int t = a[k] ^ a[k+1] ^ a[k+2];
			a[k] = a[k+1] = a[k+2] = t;
		}
	};
	
	for(int i=1; i<=n+1; ++i) if(a[i] == 0)
	{
		if(i > n)
		{
			printf("NO\n");
			return;
		}
		
		if(i % 2 == 1)
		{
			for(int j=i; j>=3; j-=2)
				push_ans(j-2);
			break;
		}
		else if(a[i+1] == 1)
		{
			push_ans(i-1);
			for(int j=i-1; j>=3; j-=2)
				push_ans(j-2);
			break;
		}
		else push_ans(i-1);
	}
	
	for(int i=1; i<=n; ++i) if(a[i])
	{
		if(a[i+1]) push_ans(i-1);
		else
		{
			push_ans(i);
			if(a[i]) push_ans(i-1);
		}
	}
	
	printf("YES\n");
	printf("%d\n",(int)ans.size());
	for(int x: ans) printf("%d ",x);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}