#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int l=n+1,r=0,f=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
				l=min(l,i),r=max(r,i);
		for(int i=l;i<=r;i++)
			if(s[i]=='1')
				f=0;
		if(l==n+1)
			puts("0");
		else if(f)
			puts("1");
		else
			puts("2");
	}
	return 0;
}