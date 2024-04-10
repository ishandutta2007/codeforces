#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

void solve(void)
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	
	if(!z)
	{
		for(int i=1; i<=x+1; ++i) putchar('0');
		for(int i=1; i<=y; ++i) putchar('0' + (i&1));
		putchar('\n');
		return;
	}
	
	if(y%2==0 && y) putchar('0'), --y;
	
	for(int i=1; i<=z+1; ++i) putchar('1');
	for(int i=1; i<=y; ++i) putchar('0' + !(i&1));
	for(int i=1; i<=x; ++i) putchar('0');
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}