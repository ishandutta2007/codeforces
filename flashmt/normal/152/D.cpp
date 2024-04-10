#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <set>
using namespace std;

int m,n,r[1010],c[1010],maxc[1010],maxr[1010],R,C,d[1010][1010],step,total;
string a[1010];

int fill(int x,int xx,int y,int yy)
{
	int cnt=0;
	for (int i=x+1;i<xx;i++)
	{
		if (a[i][y]=='.' || a[i][yy]=='.') return 1234567;
		cnt+=(d[i][y]!=step)+(d[i][yy]!=step);
		d[i][y]=d[i][yy]=step;
	}
	for (int j=y;j<=yy;j++)
	{
		if (a[x][j]=='.' || a[xx][j]=='.') return 1234567;
		cnt+=(d[x][j]!=step)+(d[xx][j]!=step);
		d[x][j]=d[xx][j]=step;
	}
	return cnt;
}

void att(int x1,int x2,int y1,int y2,int x3,int x4,int y3,int y4)
{
	if (x2-x1<2 || y2-y1<2 || x4-x3<2 || y4-y3<2) return;
	++step;
	if (fill(x1,x2,y1,y2)+fill(x3,x4,y3,y4)==total)
	{
		puts("YES");
		cout << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << endl;
		cout << x3+1 << ' ' << y3+1 << ' ' << x4+1 << ' ' << y4+1 << endl;
		exit(0);
	}
}

void check(int m,int r[],int maxr[],int &R)
{
	for (int i=0;i<m;i++)
		if (maxr[i]>=3) 
			r[R++]=i;
	if (R>4) 
	{
		for (int i=2;i;i--) r[4-i]=r[R-i];
		R=4;
	}
}

int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++) 
	{
		cin >> a[i];
		for (int j=0;j<n;j++) total+=a[i][j]=='#';
	}
	
	// row
	for (int i=0;i<m;i++)
		for (int j=0,cnt=0;j<n;j++) 
			if (a[i][j]=='#')
			{
				cnt++;
				maxr[i]=max(maxr[i],cnt);
			}
			else cnt=0;		
	check(m,r,maxr,R);
	
	// column
	for (int j=0;j<n;j++)
		for (int i=0,cnt=0;i<m;i++)
			if (a[i][j]=='#')
			{
				cnt++;
				maxc[j]=max(maxc[j],cnt);
			}
			else cnt=0;	
	check(n,c,maxc,C);	
	
	// attemp
	for (int x1=0,x2=1;x2<R;x2++)
		for (int y1=0;y1<C;y1++)
			for (int y2=y1+1;y2<C;y2++)
				for (int x3=0;x3<R;x3++)
					for (int x4=x3+1;x4<R;x4++)
						for (int y3=0;y3<C;y3++)
							for (int y4=y3+1;y4<C;y4++)
								att(r[x1],r[x2],c[y1],c[y2],r[x3],r[x4],c[y3],c[y4]);
	puts("NO");
}