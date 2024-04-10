#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
char s[N];
void sol()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int b=0;
	if(s[n]!='B')
	{
		puts("NO");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='A')
			b++;
		else
			b--;
		if(b<0)
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}