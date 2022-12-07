#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
int n, k, i;
char a [N];
char b [N];

bool check ()
	{
	for (i=0; i<n; i++)
		if (a[i] != b[i])
			break;
	if (i==n)
		return true;
	return (a[i]<b[i]);
	}

int main ()
	{
	scanf("%d%d%s", &n, &k, a);
	
	for (i=0; i<n; i++)
		b[i] = a[i%k];
	
	if (check() == true)
		return printf("%d\n%s\n", n, b), 0;
	
	for (i=k-1; i>=0; i--)
		if (b[i] < '9')
			{
			b[i]++;
			break;
			}

	for (i++; i<n; i++)
		b[i] = '0';

	for (i=0; i<n; i++)
		b[i] = b[i%k];
	
	return printf("%d\n%s\n", n, b), 0;
	}