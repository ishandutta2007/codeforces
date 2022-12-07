#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 101;
int q, my, mx, y, x;
int n, i, j;
char t [N][N];

void solve ()
	{
	scanf ("%d%d", &my, &mx);
	
	for (y=1; y<=my; y++)
		scanf ("%s", t[y]+1);
	
	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			if (t[y][x] == 'A')
				break;
		if (x<=mx)
			break;
		}
	
	if (y>my)
		{
		printf ("MORTAL\n");
		return;
		}
	
	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			if (t[y][x] == 'P')
				break;
		if (x<=mx)
			break;
		}
	
	if (y>my)
		{
		printf ("0\n");
		return;
		}
	
	for (x=1; x<=mx; x++)
		if (t[1][x]=='P')
			break;
	
	if (x>mx)
		{
		printf ("1\n");
		return;
		}
	
	for (x=1; x<=mx; x++)
		if (t[my][x]=='P')
			break;
	
	if (x>mx)
		{
		printf ("1\n");
		return;
		}
	
	for (y=1; y<=my; y++)
		if (t[y][1]=='P')
			break;
	
	if (y>my)
		{
		printf ("1\n");
		return;
		}
	
	for (y=1; y<=my; y++)
		if (t[y][mx]=='P')
			break;
	
	if (y>my)
		{
		printf ("1\n");
		return;
		}
	
	if (t[1][1]=='A')
		{
		printf ("2\n");
		return;
		}
	
	if (t[1][mx]=='A')
		{
		printf ("2\n");
		return;
		}
	
	if (t[my][1]=='A')
		{
		printf ("2\n");
		return;
		}
	
	if (t[my][mx]=='A')
		{
		printf ("2\n");
		return;
		}
	
	for (y=1; y<=my; y++)
		{
		for (x=1; x<=mx; x++)
			if (t[y][x] == 'P')
				break;
		if (x>mx)
			{
			printf ("2\n");
			return;
			}
		}
	
	for (x=1; x<=mx; x++)
		{
		for (y=1; y<=my; y++)
			if (t[y][x] == 'P')
				break;
		if (y>my)
			{
			printf ("2\n");
			return;
			}
		}
	
	for (y=1; y<=my; y++)
		if (t[y][1]=='A')
			break;
	
	if (y<=my)
		{
		printf ("3\n");
		return;
		}
	
	for (y=1; y<=my; y++)
		if (t[y][mx]=='A')
			break;
	
	if (y<=my)
		{
		printf ("3\n");
		return;
		}
	
	for (x=1; x<=mx; x++)
		if (t[1][x]=='A')
			break;
	
	if (x<=mx)
		{
		printf ("3\n");
		return;
		}
	
	for (x=1; x<=mx; x++)
		if (t[my][x]=='A')
			break;
	
	if (x<=mx)
		{
		printf ("3\n");
		return;
		}
	
	printf ("4\n");
	}

int main ()
	{
	scanf ("%d", &q);
	while (q--)
		solve();
	return 0;
	}