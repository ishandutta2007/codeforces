#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 40 + 5;
const int MAXA = 2e6 + 5;

vector<int> fact[MAXA];

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	int ans = 1;
	for(int i=1; n-i+1 >= n/2; ++i)
	{
		int has = 0;
		vector<int> vec;
		for(int j=i; j<=n; ++j)
		{
			int x = a[j] - a[i];
			if(x == 0){ ++has; continue;}
			for(int k=1; k*k<=x; ++k) if(x%k == 0)
			{
				vec.push_back(k);
				if(k*k != x) vec.push_back(x/k);
			}
		}
		if(has >= n / 2){ printf("-1\n"); return;}
		
		sort(vec.begin(), vec.end());
		for(int l=0,r=0; l<(int)vec.size(); l=r)
		{
			while(r<(int)vec.size() && vec[r] == vec[l]) ++r;
			if(r - l + has >= n / 2)
				ans = max(ans, vec[l]);
		}
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}