#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,test,x[222222],tp[222222],ans[111111],cnt;
char opt[11];
multiset<int> s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='+') tp[i]=1;
		else 
		{
			tp[i]=2;
			scanf("%d",&x[i]);
		}
	}
	cnt=n;
	for (int i=2*n;i>=1;i--)
	{
		if (tp[i]==2)
		{
			if (s.empty());
			else if ((*s.begin())<=x[i]) 
			{
				printf("NO\n");
				return 0;
			}
			s.insert(x[i]);
		}
		else 
		{
			if (s.empty())
			{
				printf("NO\n");
				return 0;
			}
			ans[cnt]=*s.begin();cnt--;
			s.erase(s.begin());
		}
	}
	printf("YES\n");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return Accepted;
}