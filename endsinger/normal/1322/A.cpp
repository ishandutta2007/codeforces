#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
int n,v,t;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
			v++;
		else
			v--;
		if(v<0||(v==0&&s[i]=='('))
			t++;
	}
	printf("%d\n",v?-1:t);
	return 0;
}