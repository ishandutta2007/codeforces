#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,ban,cnt1,cnt2,res,p1,p2;
pair<int,int> arr1[55555],arr2[55555];
bool used[111][111];
void ask(int c,int x,int y)
{
	printf("%d %d %d\n",c,x,y);
	fflush(stdout);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if ((i+j)&1) arr1[++cnt1]=make_pair(i,j);
			else arr2[++cnt2]=make_pair(i,j);
		}
	}
	p1=p2=1;
	for (int i=1;i<=n*n;i++)
	{
		scanf("%d",&res);
		if (res==1)
		{
			if (p2<=cnt2)
			{
				ask(2,arr2[p2].first,arr2[p2].second);
				p2++;
			}
			else
			{
				ask(3,arr1[p1].first,arr1[p1].second);
				p1++;
			}
		}
		else
		{
			if (p1<=cnt1)
			{
				ask(1,arr1[p1].first,arr1[p1].second);
				p1++;
			}
			else 
			{
				if (res==2)
				{
					ask(3,arr2[p2].first,arr2[p2].second);
					p2++;
				}
				else
				{
					ask(2,arr2[p2].first,arr2[p2].second);
					p2++;
				}
			}
		}
	}
	return Accepted;
}