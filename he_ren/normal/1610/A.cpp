#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n == 1 && m == 1) printf("0\n");
	else if(n == 1 || m == 1)
	{
		printf("%d\n",1);
	}
	else
	{
		printf("%d\n",2);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}