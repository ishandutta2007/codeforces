#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int M = (1<<11);
const int N = 2005;
int my, mx, y, x, sp;
int cy [N][N];
int cx [N][N];
char t [N][N];
int dpx [N][N];
int dpy [N][N];
int ty [N][M+M];
int tx [N][M+M];

void add (int& u, const int& v)
	{
	u += v;
	if (u>=mod)
		u-=mod;
	}

void update (int* tree, int a, int b, int v)
	{
	a += M;
	b += M;
	if (a>b) return;
	add(tree[a], v);
	if (a==b) return;
	add(tree[b], v);
	while (a/2 != b/2)
		{
		if (a%2==0) add(tree[a+1], v);
		if (b%2==1) add(tree[b-1], v);
		a /= 2;
		b /= 2;
		}
	}

int query (int* tree, int u)
	{
	int res = 0;
	for (u+=M; u!=0; u/=2)
		add(res, tree[u]);
	return res;
	}

int main ()
	{
	scanf ("%d%d",&my,&mx);
	
	for (y=1; y<=my; y++)
		scanf ("%s", t[y]+1);
	
	if (mx==1 && my==1)
		return printf ("1\n"), 0;
	
	for (y=my; y>=1; y--)
		for (x=1; x<=mx; x++)
			{
			cy[y][x] = cy[y+1][x];
			if (t[y+1][x]=='R')
				cy[y][x]++;
			}
	
	for (x=mx; x>=1; x--)
		for (y=1; y<=my; y++)
			{
			cx[y][x] = cx[y][x+1];
			if (t[y][x+1]=='R')
				cx[y][x]++;
			}
	
//	for (y=1; y<=my; y++)
//		{
//		for (x=1; x<=mx; x++)
//			printf ("%d ",cy[y][x]);
//		printf ("\n");
//		}
//	printf ("\n");
	
//	sp = mx-1-cx[1][1];
//	assert(sp>=0);
//	update(tx[y], 1+1, 1+sp, dpy[y][x]);
//	
//	sp = my-y-cy[y][x];
//	assert(sp>=0);
//	update(ty[x], y+1, y+sp, dpx[y][x]);
	
	dpx[1][1] = 1;
	dpy[1][1] = 1;
	
	for (y=1; y<=my; y++)
		for (x=1; x<=mx; x++)
			{
			if (y!=1 || x!=1)
				{
				dpy[y][x] = query(ty[x], y);
				dpx[y][x] = query(tx[y], x);
				}
			
	//		printf ("y=%d x=%d\n", y, x);
	//		printf ("dpx = %d dpy=%d\n",dpx[y][x], dpy[y][x]);
			
			sp = mx-x-cx[y][x];
			assert(sp>=0);
			update(tx[y], x+1, x+sp, dpy[y][x]);
			
			sp = my-y-cy[y][x];
			assert(sp>=0);
			update(ty[x], y+1, y+sp, dpx[y][x]);
			}
	
	printf ("%d\n",(dpy[my][mx]+dpx[my][mx])%mod);
	return 0;
	}