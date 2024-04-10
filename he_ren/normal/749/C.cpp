#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 2e5 + 5;

char s[MAXN];

struct Node
{
	bool type;
	int lst,nxt;
}a[MAXN];
int rem[2],cnt[2];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; ++i)
	{
		a[i] = (Node){s[i]=='D', i-1, i+1};
		++rem[a[i].type];
	}	
	a[1].lst=n; a[n].nxt=1;
	
	for(int i=1; rem[0] && rem[1]; i=a[i].nxt)
	{
		bool t=a[i].type;
		if(cnt[!t])
		{
			--rem[t];
			--cnt[!t];
			a[a[i].lst].nxt = a[i].nxt;
			a[a[i].nxt].lst = a[i].lst;
			continue;
		}
		else ++cnt[t];
	}
	if(rem[1]) putchar('D');
	else putchar('R');
	return 0;
}