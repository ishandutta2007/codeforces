#include<cstdio>
#include<cstring>
#include<stack>
const int MAXN = 1e6 + 5;
using namespace std;

char s[MAXN];
stack<int> a;

int main(void)
{
	scanf("%s",s+1);
	int n = strlen(s+1);
	
	a.push(0);
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='{') a.push(1);
		if(s[i]=='[') a.push(2);
		if(s[i]=='(') a.push(3);
		if(s[i]=='<') a.push(4);
		int x=0;
		if(s[i]=='}') x=-1;
		if(s[i]==']') x=-2;
		if(s[i]==')') x=-3;
		if(s[i]=='>') x=-4;
		if(x<0)
		{
			if(a.top()>0)
			{
				if(a.top()+x != 0) ++ans;
				a.pop();
			}
			else
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	if(a.top()) printf("Impossible");
	else printf("%d",ans);
	return 0;
}