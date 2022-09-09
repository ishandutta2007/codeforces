#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	if(d%3)
	{
		if(n%3) printf("Alice\n");
		else printf("Bob\n");
		return;
	}
	
	n %= d+1;
	
	if(n == d) printf("Alice\n");
	else if(n%3) printf("Alice\n");
	else printf("Bob\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}

/*
0 1 2 3 4 5 6
1 0 0 1 0 0 1 0 0 1 0 0

0 1 0 0 1 0 0 1 0 0 1 0

0 0 1 0 0 1 
*/