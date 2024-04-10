#include <bits/stdc++.h>
using namespace std;

int n, x, y, mx, my, dy, dx;
char t [101][101];
int s [101][101];

void check (void)
	{
	int xx=x+dx;
	int yy=y+dy;
	if (xx<0 || xx>=mx || yy<0 || yy>=my)
		return;
	s[yy][xx]++;
	return;
	}

int main ()
	{
	scanf ("%d%d",&my,&mx);
	for (y=0; y!=my; y++)
		scanf ("%s",t[y]);
	for (y=0; y!=my; y++)
		for (x=0; x!=mx; x++)
			if (t[y][x]=='*')
				{
				dx=-1;
				dy=-1;
				check();
				
				dx=-1;
				dy= 0;
				check();
				
				dx=-1;
				dy= 1;
				check();
				
				dx= 0;
				dy= 1;
				check();
				
				dx= 0;
				dy=-1;
				check();
				
				dx= 1;
				dy=-1;
				check();
				
				dx= 1;
				dy= 0;
				check();
				
				dx= 1;
				dy= 1;
				check();
				}
	for (y=0; y!=my; y++)
		for (x=0; x!=mx; x++)
			if (t[y][x]=='.')
				t[y][x]='0';
	for (y=0; y!=my; y++)
		for (x=0; x!=mx; x++)
			{
			if (t[y][x]>='0' && t[y][x]<='8')
				if (t[y][x]-'0'!=s[y][x])
					{
					printf ("NO\n");
					return 0;
					}
			}
	printf ("YES\n");
	return 0;
	}