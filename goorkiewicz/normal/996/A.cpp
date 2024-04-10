#include <bits/stdc++.h>
using namespace std;

int n, out;

int main ()
	{
	scanf ("%d",&n);
	out+=(n/100);
	n%=100;
	out+=(n/20);
	n%=20;
	out+=(n/10);
	n%=10;
	out+=(n/5);
	n%=5;
	out+=(n/1);
	n%=1;
	printf ("%d\n",out);
	return 0;
	}