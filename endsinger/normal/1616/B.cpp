#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
char s[N];
void out(int p)
{
	for(int i=1;i<=p;i++)
		printf("%c",s[i]);
	for(int i=p;i>=1;i--)
		printf("%c",s[i]);
	puts("");
}
void sol()
{
	scanf("%d%s",&n,s+1);
	if(n==1)
	{
		out(1);
		return;
	}
	if(s[1]==s[2])
	{
		out(1);
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]<s[i+1])
		{
			out(i);
			return;
		}
	}
	out(n);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}