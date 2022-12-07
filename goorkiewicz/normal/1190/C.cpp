#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, i, j;
int P0, P1, S0, S1, p0, p1, s0, s1;
char t [100002];

int main ()
	{
	scanf ("%d%d%s", &n, &k, t);
	
	P0 = -1;
	while (t[P0+1]=='0')
		P0++;
	P1 = -1;
	while (t[P1+1]=='1')
		P1++;
	S0 = n;
	while (t[S0-1]=='0')
		S0--;
	S1 = n;
	while (t[S1-1]=='1')
		S1--;
	
	//printf ("P0=%d P1=%d S0=%d S1=%d\n",P0,P1,S0,S1);
	
	if (P0+k>=S0-1)
		return printf ("tokitsukaze\n"), 0;
	if (P1+k>=S1-1)
		return printf ("tokitsukaze\n"), 0;
	
	for (i=0; i+k<n; i++)
		{
		p0 = P0;
		p1 = P1;
		s0 = S0;
		s1 = S1;
		
		if (p0+1>=i)
			p0 = i+k-1;
		if (p1>=i)
			p1 = i-1;
		
		if (s0-1<=i+k-1)
			s0 = i;
		if (s1<=i+k-1)
			s1 = i+k;
		
		//printf ("i=%d p0=%d p1=%d s0=%d s1=%d\n",i,p0,p1,s0,s1);
		if (p0+k<s0-1 && p1+k<s1-1)
			return printf ("once again\n"), 0;
		}
	
	for (i=0; i+k<n; i++)
		{
		p0 = P0;
		p1 = P1;
		s0 = S0;
		s1 = S1;
		
		if (p1+1>=i)
			p1 = i+k-1;
		if (p0>=i)
			p0 = i-1;
		
		if (s1-1<=i+k-1)
			s1 = i;
		if (s0<=i+k-1)
			s0 = i+k;
		
		if (p0+k<s0-1 && p1+k<s1-1)
			return printf ("once again\n"), 0;
		}
	
	return printf ("quailty\n"), 0;
	}