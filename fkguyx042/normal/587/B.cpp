#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
typedef pair<int,int> pii;
vector <pii> A;
int main()
{
	// freopen("input.txt", "r", stdin);
	// ios_base::sync_with_stdio(0);
	long long int n,l,k;
	scanf("%I64d %I64d %I64d", &n, &l, &k);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		A.push_back(pii(x,i));
	}
	sort(A.begin(), A.end());
	vector < vector <int> > dp(n, vector <int> (k+1));
	int ptr = 0;
	long long int t1 = l%n, t2 = l/n;
	vector <long long int> mult(n);
	vector <int> rpos(n);
	for (int i = 0; i < n; ++i)
	{
		while(ptr+1 < n && A[ptr+1].first <= A[i].first)
			ptr++;
		rpos[i] = ptr;
		dp[i][0] = 1;
		mult[i] = ((A[i].second < t1)?t2+1:t2);
	}
	long long int fans = 0;
	for (int j = 1; j <= k; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			dp[i][j] = dp[rpos[i]][j-1];
			long long int temp = mult[i];
			temp-=(j-1);
			if(temp < 0)
				temp = 0;
			else
				temp%=MOD;
			fans = (fans + temp*dp[i][j])%MOD;
			if(i)
				dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
		}
	}
	printf("%I64d\n", fans);
	return 0;
}