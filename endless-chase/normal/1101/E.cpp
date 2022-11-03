#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,y,mxx,mxy;
char s[11];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s%d%d",s,&x,&y);
		if (x>y) swap(x,y);
		if (s[0]=='+')
		{
			mxx=max(mxx,x);
			mxy=max(mxy,y);
		}
		else 
		{
			if (mxx<=x && mxy<=y) printf("YES\n");
			else printf("NO\n");
		}
	}
	return Accepted;
}