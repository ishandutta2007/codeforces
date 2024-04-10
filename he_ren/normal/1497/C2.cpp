#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	for(int i=1; i<=d-3; ++i) printf("1 ");
	n -= d - 3;
	if(n&1) printf("%d %d %d\n",n / 2,n / 2,1);
	else if(n == 4) printf("1 1 2\n");
	else if((n / 2) % 2) printf("%d %d %d\n",n / 2 - 1,n / 2 - 1, 2);
	else printf("%d %d %d\n",n / 2, n / 4, n / 4);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}