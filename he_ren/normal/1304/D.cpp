#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;

char s[MAXN];
int a[MAXN],b[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i) a[i]=n-i+1;
	for(int i=1,j=1; i<n; i=j)
	{
		while(j<n && s[j]==s[i]) ++j;
		if(s[i]=='<') reverse(a+i,a+j+1);
	}
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	putchar('\n');
	
	for(int i=1; i<=n; ++i) a[i]=i;
	for(int i=1,j=1; i<n; i=j)
	{
		while(j<n && s[j]==s[i]) ++j;
		if(s[i]=='>') reverse(a+i,a+j+1);
	}
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}