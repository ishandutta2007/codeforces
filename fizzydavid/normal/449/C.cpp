#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
const int INF=1<<28;
int n;
bool used[100111];
vector<int> ans;
int main()
{
	cin>>n;
	for(int i=3;i<=n/2;i++)
	{
		if(!used[i]&&(i&1))
		{
			int tmp=0;
			for(int j=i;j<=n;j+=i)
			{
				if(!used[j])
				{
					tmp++;
				}
			}
			if(tmp&1)
			{
				ans.pb(i);
				for(int j=3*i;j<=n;j+=i)
				{
					if(!used[j])
					{
						ans.pb(j);
						used[j]=1;
					}
				}
			}
			else
			{
				for(int j=i;j<=n;j+=i)
				{
					if(!used[j])
					{
						ans.pb(j);
						used[j]=1;
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i+=2)
	{
		if(!used[i])ans.pb(i);
	}
	printf("%d\n",ans.size()/2);
	for(int i=0;i<ans.size()/2;i++)
	{
		printf("%d %d\n",ans[i*2],ans[i*2+1]);
	}
// 	system("pause");
	return 0;
}