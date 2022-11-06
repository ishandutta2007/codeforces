#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
using namespace std;
int num[N],ans[N];
char s[N];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++) num[i]=s[i]-'0';
	int l=1,r=n;
	if(num[l]!=num[r])
	{
		num[l]--;
		num[l+1]+=10;
		if(num[l]==0) l++;
	}
	for(;l<=r;l++,r--)
	{
		if(num[l]!=num[r])
		{
			if(num[l]-num[r]>=10) num[r]+=10,num[r-1]--;
			if(num[l]-num[r]==1) num[l]--,num[l+1]+=10;
		}
		if(num[l]!=num[r]){puts("0");return 0;}
		if(l!=r) ans[l]=num[l]-num[r]/2,ans[r]=num[r]/2;
		else
		{
			if(num[l]&1){puts("0");return 0;}
			ans[l]=num[l]/2;
		}
	}
	for(int i=1;i<=n;i++)
	if(ans[i]<0 || ans[i]>9){puts("0");return 0;}
	
	int i=1;
	for(;!ans[i];i++);
	for(;i<=n;i++) printf("%d",ans[i]);
	return 0;
}