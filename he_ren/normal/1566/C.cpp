#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char a[MAXN], b[MAXN];
inline int type(int i)
{
	return a[i] == b[i];
}

void solve(void)
{
	int n;
	scanf("%d%s%s",&n,a+1,b+1);
	
	int ans = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && type(i) == type(j)) ++j;
		if(type(i) == 0)
		{
			ans += (j - i) * 2;
			continue;
		}
		
		for(int k=i; k<j; ++k)
		{
			if(k+1 >= j || a[k] == a[k+1])
			{
				ans += a[k] == '0';
				continue;
			}
			ans += 2;
			++k;
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