#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(a > b) swap(a,b);
	b = min((ll)b, 3ll * a);
	printf("%lld\n",((ll)a + b) / 4);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}