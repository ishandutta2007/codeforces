#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n;
int a[MAXN];

vector<int> A,B;
vector<pair<int,int> > ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	for (int i = n;i >= 1;i--)
	{
		if (a[i] == 1)
		{
			ans.push_back(make_pair(i,i));
			A.push_back(i);
		}
		if (a[i] == 2)
		{
			if (!A.size())
			{
				puts("-1");
				return 0;
			}
			int t = A.back();
			ans.push_back(make_pair(t,i));
			B.push_back(i);
			A.pop_back();
		}
		if (a[i] == 3)
		{
			ans.push_back(make_pair(i,i));
			if (B.size())
			{
				ans.push_back(make_pair(i,B.back()));
				B.pop_back();
			}
			else if (A.size())
			{
				ans.push_back(make_pair(i,A.back()));
				A.pop_back();
			}
			else
			{
				puts("-1");
				return 0;
			}
			B.push_back(i);
		}
	}
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}