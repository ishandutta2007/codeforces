#include <bits/stdc++.h>
using namespace std;

int n, i, x, out;
bool taken [200002];
int t [200002];
stack <int> Stack;

int main ()
	{
	scanf ("%d",&n);
	for (i=1; i<=n; i++)
		scanf ("%d",&t[i]);
	for (i=n; i>=1; i--)
		Stack.push(t[i]);
	for (i=1; i<=n; i++)
		{
		scanf ("%d",&x);
		if (taken[x]==true)
			{
			printf ("0 ");
			continue;
			}
		for (out=0; Stack.top()!=x; out++)
			{
			taken[Stack.top()]=true;
			Stack.pop();
			}
		taken[x]=true;
		Stack.pop();
		printf ("%d ",out+1);
		}
	printf ("\n");
	return 0;
	}