#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	int ans = (a&1) + (b&1) * 2 + (c&1) * 3;
	for(int i=-5; i<=5; ++i)
		for(int j=-5; j<=5; ++j)
			for(int k=-5; k<=5; ++k)
			{
				ll x = a / 2 + i, y = b / 2 + j, z = c / 2 + k;
				if(x < 0 || y < 0 || z < 0) continue;
				if(x > a || y > b || z > c) continue;
				
				ll dif = (2 * x - a) + (2 * y - b) * 2 + (2 * z - c) * 3;
				ans = min((ll)ans, abs(dif));
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