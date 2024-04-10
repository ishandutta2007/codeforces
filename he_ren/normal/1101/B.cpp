#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 5e5 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	int flag=0;
	int l=n+1, r=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='[' && flag==0)
			flag=1;
		if(s[i]==':' && flag==1)
		{
			flag=2; l=i+1;
			break;
		}
	}
	if(flag!=2){ printf("-1"); return 0;}
	
	for(int i=n; i>=l; --i)
	{
		if(s[i]==']' && flag==2)
			flag=3;
		if(s[i]==':' && flag==3)
		{
			flag=4; r=i-1;
			break;
		}
	}
	if(flag!=4){ printf("-1"); return 0;}
	
	int ans=4;
	for(int i=l; i<=r; ++i)
		if(s[i]=='|') ++ans;
	printf("%d",ans);
	return 0;
}