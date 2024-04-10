#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	int ans = 0, cur = 1;
	while(d)
	{
		if(d & 1) ans = (ans + cur) %mod;
		cur = (ll)cur * n %mod;
		d >>= 1;
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