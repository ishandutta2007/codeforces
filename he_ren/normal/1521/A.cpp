#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	if(b == 1) printf("NO\n");
	else
	{
		printf("YES\n");
		if(b == 2) printf("%d %d %d\n",a,a*3,a*4);
		else printf("%d %lld %lld\n",a,(ll)a*(b-1),(ll)a*b);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}