#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	int mx = 0;
	for(int i=0; i<=n; i+=d)
	{
		int res = (int)(sqrt((ll)n*n - (ll)i*i) / d) + i/d;
		mx = max(mx, res);
	}
	
	if(mx&1) printf("Ashish\n");
	else printf("Utkarsh\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}