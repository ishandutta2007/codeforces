#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int mn[11],n,c[1111],ans,len;
char str[11];
string s;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=7;i++) mn[i]=4e8;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		scanf("%s",str);
		len=strlen(str);
		sort(str,str+len);
		s="";
		for (int j=0;j<len;j++) s=s+str[j];
		if (s=="A") mn[1]=min(mn[1],c[i]);
		else if (s=="B") mn[2]=min(mn[2],c[i]);
		else if (s=="C") mn[4]=min(mn[4],c[i]);
		else if (s=="AB") mn[3]=min(mn[3],c[i]);
		else if (s=="AC") mn[5]=min(mn[5],c[i]);
		else if (s=="BC") mn[6]=min(mn[6],c[i]);
		else mn[7]=min(mn[7],c[i]);
	}
	ans=min(mn[1]+mn[2]+mn[4],min(mn[1]+mn[6],min(mn[2]+mn[5],min(mn[4]+mn[3],mn[7]))));
	ans=min(ans,min(mn[3]+mn[5],min(mn[3]+mn[6],mn[5]+mn[6])));
	if (ans>=3e8) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}