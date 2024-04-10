#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,t,pre[3],x;
int main() 
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n=n*2;
		pre[0]=pre[1]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
//			printf("%d %d %d\n",i,x%2,pre[x%2]);
			if(pre[x%2]==0) 
			{
				pre[x%2]=i;
				continue;
			}
			if(cnt==n/2-1) break;
			printf("%d %d\n",pre[x%2],i);
			pre[x%2]=0;
			cnt++;
		}
	}
}