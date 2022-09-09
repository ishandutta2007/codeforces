#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	if(n%2 == 0)
	{
		printf("%d\n",d%n? d%n: n);
		return;
	}
	
	int len = n / 2;
	int t = (d - 1) / len; d -= t * len;
	int x = (ll)t * (len+1) % n;
	x = (x + d) %n;
	printf("%d\n",x? x: n);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}