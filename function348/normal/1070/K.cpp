#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=200010,p=1000000007;
int n,k;
int ans[N];
int a[N];
int s;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if (s%k!=0)
	{
		printf("No\n");
		return 0;
	}
	s/=k;
	for (int i=1,j=0,k=0,l=0;i<=n;i++)
	{
		j+=a[i];
		if (j>s)
		{
			printf("No\n");
			return 0;
		}
		if (j==s)
		{
			ans[++l]=i-k;
			j=0;k=i;
		}
	}
	printf("Yes\n");
	for (int i=1;i<=k;i++) printf("%d ",ans[i]);
	return 0;
}