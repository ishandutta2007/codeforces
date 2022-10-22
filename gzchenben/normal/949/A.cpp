#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n,ans;
char s[200005];
vector<int> Vec0,Vec1;
vector<int> ch[200005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			if(Vec1.empty())
			{
				ans++;
				Vec1.push_back(ans);
			}
			ch[Vec1.back()].push_back(i);
			Vec0.push_back(Vec1.back());
			Vec1.pop_back();
		}
		else
		{
			if(Vec0.empty()) 
			{
				printf("-1\n");
				return 0;
			}
			ch[Vec0.back()].push_back(i);
			Vec1.push_back(Vec0.back());
			Vec0.pop_back();
		}
	}
	if(Vec1.size()) 
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",ch[i].size());
		for(auto &p : ch[i])
		{
			printf("%d ",p);
		}
		printf("\n");
	}
}