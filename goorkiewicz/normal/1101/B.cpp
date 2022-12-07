#include <bits/stdc++.h>
using namespace std;

bool op1, cl1;
int n, i, j, op, cl, out;
char s [500002];

int main ()
	{
	scanf ("%s",s+1);
	n = strlen(s+1);
	for (i=1; i<=n; i++)
		{
		if (s[i]=='[')
			op1=true;
		if (s[i]==':' && op1==true)
			break;
		}
	op = i;
	for (i=n; i>=1; i--)
		{
		if (s[i]==']')
			cl1=true;
		if (s[i]==':' && cl1==true)
			break;
		}
	cl = i;
	if (cl<=op)
		{
		printf ("-1\n");
		return 0;
		}
	out = 4;
	for (i=op+1; i<cl; i++)
		if (s[i]=='|')
			out++;
	printf ("%d\n",out);
	return 0;
	}