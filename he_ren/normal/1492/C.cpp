#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

char s[MAXN], t[MAXM];
int l[MAXM], r[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	
	for(int i=1,j=1; j<=m; ++i)
		if(s[i] == t[j]) l[j++] = i;
	for(int i=n,j=m; j>=1; --i)
		if(s[i] == t[j]) r[j--] = i;
	
	int ans = 0;
	for(int i=1; i<m; ++i)
		ans = max(ans, r[i+1] - l[i]);
	printf("%d",ans);
	return 0;
}