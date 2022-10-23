#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n;
	int r[3], c[3], x, y;
	scanf("%d",&n);
	for(int i=0; i<3; ++i)
		scanf("%d%d",&r[i],&c[i]);
	scanf("%d%d",&x,&y);
	
	sort(r, r+3); sort(c, c+3);
	
	if((r[1] == 1 || r[1] == n) && (c[1] == 1 || c[1] == n))
	{
		if(x == r[1] || y == c[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	else
	{
		if((x + y) % 2 == (r[1] + c[1]) % 2 && x % 2 != r[1] % 2)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}