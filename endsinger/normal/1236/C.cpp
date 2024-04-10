#include<bits/stdc++.h>
using namespace std;
const int N=305;
vector<int>a[N];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i&1)
			{
				a[j].push_back(++cnt);			
			}
			else
			{
				a[n-j+1].push_back(++cnt);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:a[i])
			printf("%d ",j);
		puts("");
	}
	return 0;
}