#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int c,d;
	scanf("%d%d",&c,&d);
	
	if(c%2 != d%2) printf("-1\n");
	else
	{
		if(c == 0 && d == 0) printf("0\n");
		else
		{
			if(c == d) printf("%d\n",c == 0? 0: 1);
			else printf("%d\n",2);
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}