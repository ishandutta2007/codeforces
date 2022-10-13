#include <iostream>
#include <algorithm>
#include <cstdio>
#define sqr(x) (x)*(x)
using namespace std;

struct point
{
	int x,y,type,pos,dist;
	void read(int i)
	{
		cin >> x >> y;
		type=1; pos=i; 
		if (x<0) x=-x, type++;
		if (y<0) y=-y, type+=2;
		dist=x*x+y*y;
	}
};

int n,re=int(1e9),rx,ry,rxx,ryy;
point a[100100];

bool cmp(point i,point j)
{
	return i.dist<j.dist;
}

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) a[i].read(i);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n && j<=i+100;j++)
		{
			int u=sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y);
			if (u<re)
			{
				re=u;
				rx=a[i].pos; rxx=a[i].type;
				ry=a[j].pos; ryy=a[j].type;
			}
		}
	cout << rx << " " << rxx << " " << ry << " " << 5-ryy << endl;
}