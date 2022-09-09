#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXM = 1e6 + 5;

string s[MAXN];
bool has[MAXM];
int sum[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	s[0] = string(m+1, '.');
	for(int i=1; i<=n; ++i)
	{
		cin >> s[i];
		s[i] = '.' + s[i];
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i-1][j] == 'X' && s[i][j-1] == 'X')
				has[j] = 1;
	
	for(int i=1; i<=m; ++i) sum[i] = sum[i-1] + has[i];
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(sum[l] == sum[r])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}