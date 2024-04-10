#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,ch[200005];
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		char tmp;
		scanf(" %c",&tmp);
		ch[i]=tmp-'0';
	}
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(ch[i]!=ch[(i-1)%k+1]) 
		{
			flag = (ch[i]<ch[(i-1)%k+1]);
			break;
		}
	}
	if(flag) 
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d",ch[(i-1)%k+1]);
		}
		printf("\n");
		return 0;
	}
	int now=k;
	while(ch[now]==9)
	{
//		printf("%d\n",ch[now]);
		ch[now]=0;
		now--;
	}
	ch[now]++;
	for(int i=1;i<=n;i++)
	{
		printf("%d",ch[(i-1)%k+1]);
	}
	printf("\n");
	return 0;
}