#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <cstdio>
#define fi first
#define se second
using namespace std;

int n,k;
pair <int,int> a[200200];
set < pair<int,int> > ans;

int compare(int x,int y,int xx,int yy)
{
	if (x==xx && y==yy) return 0;
	if (x<xx || (x==xx && y<yy)) return -1;
	return 1;
}

void att(int l,int r,int melted,int x,int y)
{
	if (melted<0) return;
	
	if (l>r)
	{
		ans.insert(make_pair(x,y));
		return;
	}
	
	if (l==r)
	{
		if (melted || (a[l].fi*2==x && a[l].se*2==y)) ans.insert(make_pair(x,y));
		return;
	}
	
	int cmp=compare(a[l].fi+a[r].fi,a[l].se+a[r].se,x,y);
	if (!cmp) att(l+1,r-1,melted,x,y);
	else
		if (cmp<0) att(l+1,r,melted-1,x,y);
		else att(l,r-1,melted-1,x,y);
}

int main()
{
	cin >> n >> k;
	for (int i=0;i<n;i++) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a,a+n);
	
	if (k>=n) 
	{
		puts("-1");
		return 0;
	}
	
	for (int i=0;i<min(n,12);i++)
		for (int j=n-1;j>=max(n-12,0);j--)
			if (i<=j && i+n-1-j<=k)
			{
				int x=a[i].fi+a[j].fi,y=a[i].se+a[j].se;
				if (ans.count(make_pair(x,y))) continue;
				att(i+1,j-1,k-(i+n-1-j),x,y);
			}
			
	cout << ans.size() << endl;
	for (set < pair<int,int> >::iterator it=ans.begin();it!=ans.end();it++)
		printf("%.1lf %.1lf\n",0.5*(it->first),0.5*(it->second));
}