#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double db;

const int MAXN = 10005;
const db eps = 1e-10;

struct Vector
{
	db x,y;
	
	Vector (db X = 0,db Y = 0)
	{
		x = X;
		y = Y;
	}
	
	db len()
	{
		return sqrt(x * x + y * y);
	}
	
	db len2()
	{
		return x * x + y * y;
	}
	
	Vector operator + (const Vector &p)const
	{
		return Vector(x + p.x,y + p.y);
	}
	
	Vector operator - (const Vector &p)const
	{
		return Vector(x - p.x,y - p.y);
	}
	
	Vector operator * (const db &p)const
	{
		return Vector(x * p,y * p);
	}
	
	db operator * (const Vector &p)const
	{
		return x * p.y - y * p.x;
	}
}a[MAXN],A[MAXN],b[MAXN],B[MAXN],bot;

int n,m,N,M;

bool cmp(const Vector &a,const Vector &b)
{
	if ((a - bot) * (b - bot) == 0)
		return (a - bot).len() < (b - bot).len();
	return (a - bot) * (b - bot) > 0;
}

void getcircle(Vector a,Vector b,Vector c,Vector &Ct)
{
	Vector A = Vector(b.x - a.x,c.x - a.x) * 2,B = Vector(b.y - a.y,c.y - a.y) * 2;
	Vector C = Vector(b.len2() - a.len2(),c.len2() - a.len2());
	Ct = Vector((B * C) / (B * A),(A * C) / (A * B));
}

void gethull(Vector *a,int n,Vector *A,int &top)
{
	for (int i = 2;i <= n;i++)
		if (a[i].y < a[1].y || (a[i].y == a[1].y && a[i].x < a[1].x))
			swap(a[1],a[i]);
	A[top = 1] = bot = a[1];
	sort(a + 2,a + n + 1,cmp);
	for (int i = 2;i <= n;i++)
	{
		while (top > 1 && (A[top] - A[top - 1]) * (a[i] - A[top]) <= 0)
			top--;
		A[++top] = a[i];
	}
	while (top > 2 && (A[top] - A[top - 1]) * (a[1] - A[top]) <= 0)
		top--;
}

void solve(Vector *A,int l,int r,int n,Vector *b,int m)
{
	if (l == r)
		return;
	int mid = 0;
	db MIN = -1e100,MAX = 1e100,minx = min(A[l].x,A[r].x),miny = min(A[l].y,A[r].y),maxx = max(A[l].x,A[r].x),maxy = max(A[l].y,A[r].y);
	Vector o = (A[l] + A[r]) * 0.5;
	for (int i = 1;MIN < MAX && i <= n;i++)
	{
		db rad,dir = (A[l] - A[r]) * (A[i] - A[l]);
		if (dir == 0)
		{
			if (A[i].x < minx || A[i].x > maxx || A[i].y < miny || A[i].y > maxy)
				MIN = MAX + 1;
			continue;
		}
		Vector c;
		getcircle(A[l],A[i],A[r],c);
		rad = (c - o).len();
		if ((c - A[r]) * (A[l] - c) > 0)
			rad = -rad;
		if (i > l && i < r)
		{
			if (rad > MIN)
			{
				MIN = rad;
				mid = i;
			}
		}
		else
		{
			if (dir > 0)
				MIN = max(MIN,rad);
			else
				MAX = min(MAX,rad);
		}
	}
	for (int i = 1;MIN < MAX && i <= m;i++)
	{
		db rad,dir = (A[l] - A[r]) * (b[i] - A[l]);
		if (dir == 0)
		{
			if (b[i].x >= minx && b[i].x <= maxx && b[i].y >= miny && b[i].y <= maxy)
				MIN = MAX + 1;
			continue;
		}
		Vector c;
		getcircle(A[l],b[i],A[r],c);
		rad = (c - o).len();
		if ((c - A[r]) * (A[l] - c) > 0)
			rad = -rad;
		if (dir < 0)
			MIN = max(MIN,rad);
		else
			MAX = min(MAX,rad);
	}
	if (MIN < MAX - eps)
	{
		puts("YES");
		exit(0);
	}
	if (mid)
	{
		solve(A,l,mid,n,b,m);
		solve(A,mid,r,n,b,m);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	if (n == 1 || m == 1)
	{
		puts("YES");
		return 0;
	}
	for (int x,y,i = 1;i <= n;i++)
	{
		scanf("%d%d",&x,&y);
		a[i] = Vector(x,y);
	}
	for (int x,y,i = 1;i <= m;i++)
	{
		scanf("%d%d",&x,&y);
		b[i] = Vector(x,y);
	}
	gethull(a,n,A,N);
	gethull(b,m,B,M);
	solve(A,1,N,N,b,m);
	solve(B,1,M,M,a,n);
	puts("NO");
	return 0;
}