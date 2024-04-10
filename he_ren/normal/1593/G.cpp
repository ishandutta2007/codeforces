#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

char s[MAXN];
int a[MAXN], sum[MAXN];

void solve(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	for(int i=1; i<=n; ++i)
		a[i] = (s[i] == '(' || s[i] == ')') ^ (i&1)? 1: -1;
	
	for(int i=1; i<=n; ++i)
		sum[i] = sum[i-1] + a[i];
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",abs(sum[r] - sum[l-1]) / 2);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}