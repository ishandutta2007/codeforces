#include<bits/stdc++.h>
using namespace std;
char s[200005];
int T;
int main(){
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int ans=0,top=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(')	++top;
			else if(s[i]==')')
			{
				if(top)	++ans,--top;
			}
		}
		top=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='[')	++top;
			else if(s[i]==']')
			{
				if(top)	++ans,--top;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}