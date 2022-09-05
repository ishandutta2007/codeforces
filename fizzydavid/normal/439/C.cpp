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
int n,k,p,op;
vector<int>ans[111000];
queue<int>even,odd;
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	for(int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if(x&1)odd.push(x);else even.push(x);
	}
	int es=even.size(),os=odd.size();
	p=k-p;
	if(os<p||(os-p)&1||es+(os-p)/2<k-p)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		for(int i=0;i<p;i++)
		{
			int tmp=odd.front();
			odd.pop();ans[i].push_back(tmp);
		}
		for(int i=p;i<k;i++)
		{
			if(even.empty())
			{
				int tmp1=odd.front();odd.pop();
				int tmp2=odd.front();odd.pop();
				ans[i].push_back(tmp1);ans[i].push_back(tmp2);
			}
			else
			{ 
				int tmp=even.front();
				even.pop();ans[i].push_back(tmp);
			}
		}
		while(!odd.empty())
		{
			int tmp=odd.front();
			odd.pop();ans[0].push_back(tmp);
		}
		while(!even.empty())
		{
			int tmp=even.front();
			even.pop();ans[0].push_back(tmp);
		}
		for(int i=0;i<k;i++)
		{
			printf("%d",ans[i].size());
			for(int j=0;j<ans[i].size();j++)printf(" %d",ans[i][j]);
			puts("");
		}
	}
// 	system("pause");
	return 0;
}