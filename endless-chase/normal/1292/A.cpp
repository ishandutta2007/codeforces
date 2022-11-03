#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,q,cnt,x,y;
bool used[3][111111];
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		if (used[x][y])
		{
			used[x][y]=0;
			if (used[3-x][y]) cnt--;
			if (used[3-x][y+1]) cnt--;
			if (used[3-x][y-1]) cnt--;
		}
		else
		{
			used[x][y]=1;
			if (used[3-x][y]) cnt++;
			if (y+1<=n && used[3-x][y+1]) cnt++;
			if (y-1>=1 && used[3-x][y-1]) cnt++;
		}
		if (!cnt && !used[1][1] && !used[2][n]) printf("Yes\n");
		else printf("No\n");
	}
	return Accepted;
}