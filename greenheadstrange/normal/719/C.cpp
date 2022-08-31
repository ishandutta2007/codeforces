#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 200005

using namespace std;
int num[maxn];

int t,n;
int cnt;
int fdpl;
bool ndout[maxn];
int main()
{
	scanf("%d%d",&n,&t);
	getchar();
	cnt=n-2;
	for(int i=n-1;i>=0;i--)
	{
		char a;
		scanf("%c",&a);
		if(a=='.')
		{ 
			fdpl=cnt;
			continue; 
		} 
		num[cnt]=int(a)-int('0');
		cnt--;
	}
	//cout<<fdpl<<endl;
	for(int i=n-2;i>=0;i--) 
		if(num[i]>=5 && i<=fdpl)
		{
			num[i+1]++;
			for(int j=0;j<=i;j++) num[j]=0;
			t--;
			for(int j=i+1;j<=n-1;j++)
			{
				if(t<=0 || j>fdpl) break;
				else if(num[j]>=5)
				{
					num[j]=0;
					num[j+1]++;
					t--;
				}
			}
			
			break;
		}
	for(int i=fdpl+1;i<=n-1;i++) 
		if(num[i]>=10)
		{
			num[i+1]+=num[i]/10;
			num[i]%=10;
		 } 
	if(num[n-1]>0) printf("%d",num[n-1]);
	for(int i=0;i<=n-1;i++) ndout[i]=true;
	for(int i=0;i<=n-1;i++)
	{
		if(num[i]==0) ndout[i]=false;
		else break;
	}
	for(int i=n-2;i>=0;i--)
	{
		if(i<=fdpl && !ndout[i]) break;
		if(i==fdpl) printf(".");
		printf("%d",num[i]);
	}
	printf("\n");
	return 0;
}