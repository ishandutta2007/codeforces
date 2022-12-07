#include <bits/stdc++.h>
using namespace std;

int n, i, x;
char s [400001];
priority_queue < pair <int,int> , vector < pair <int,int> > , greater < pair <int,int> > > Int;
priority_queue < pair <int,int> > Ext;

int main ()
	{
	scanf ("%d",&n);
	for (i=0; i!=n; i++)
		{
		scanf ("%d",&x);
		Int.push(make_pair(x,(i+1)));
		}
	scanf ("%s",s);
	for (i=0; i!=(n+n); i++)
		{
		if (s[i]=='0')
			{
			printf ("%d ",Int.top().second);
			Ext.push(Int.top());
			Int.pop();
			}
		if (s[i]=='1')
			{
			printf ("%d ",Ext.top().second);
			Ext.pop();
			}
		}
	printf ("\n");
	return 0;
	}