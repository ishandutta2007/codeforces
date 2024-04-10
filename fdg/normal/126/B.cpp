#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>

#define ll long long

using namespace std;

char s[1000002];
int z[1000002];
set <int> f;

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	gets(s);
	int n=strlen(s);
	for(int i=1,l=0,r=0;i<n;++i)
	{
		if (i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])
			++z[i];
		if (i+z[i]-1>r)
			l=i,r=i+z[i]-1;
	}
	int pos=-1,l=-1;
	for(int i=n-1;i>=0;i--)
	{
		int len=z[i];
		if (i+len==n) len--;
		set <int>::iterator it=f.upper_bound(len);
		if (it!=f.begin())
		{
			it--;
			if (*it>l) l=*it,pos=i;
		}
		if (i+z[i]==n)
			f.insert(z[i]);
	}
	if (l==-1) printf("Just a legend\n");
	else
	{
		for(int i=0;i<l;i++)
			printf("%c",s[i+pos]);
		printf("\n");
	}
	return 0;
}