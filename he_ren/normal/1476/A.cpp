#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k >= n) printf("%d\n",(k+n-1)/n);
	else if(n%k == 0) printf("1\n");
	else printf("2\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}