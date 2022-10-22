#include<bits/stdc++.h>
using namespace std;
const int N=105;
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
		printf("%d\n",n);
	}
	return 0;
}