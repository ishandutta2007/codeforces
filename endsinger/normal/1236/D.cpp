#include<bits/stdc++.h>
using namespace std;
const int N=100005;
set<int>row[N],col[N];
int main()
{
	long long n,m;
	int k;
	scanf("%I64d%I64d%d",&n,&m,&k);
	for (int i=0;i<k;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		row[x].insert(y);
		col[y].insert(x);
	}
	for(int i=1;i<=n;i++)
		row[i].insert(0),row[i].insert(m+1);
	for(int i=1;i<=m;i++)
		col[i].insert(0),col[i].insert(n+1);
	int x=1,y=1,dir=0;
	if (row[1].count(2))
		dir=1;
	int up=0,down=n+1,left=0,right=m+1;
	long long sum=1;
	while(sum+k<n*m)
	{
		int nx=x,ny=y;
		if(dir==0)
		{
			ny=min(right-1,(*row[x].lower_bound(y))-1);
			sum+=ny-y;
			dir=(dir+1)%4;
			up=x;
		} 
		else if(dir==1)
		{
			nx=min(down-1,(*col[y].lower_bound(x))-1);
			sum+=nx-x;
			dir=(dir+1)%4;
			right=y;
		} 
		else if(dir==2)
		{
			ny=max(left+1,(*(--row[x].lower_bound(y)))+1);
			sum+=y-ny;
			dir=(dir+1)%4;
			down=x;
		} 
		else if(dir==3)
		{
			nx=max(up+1,(*(--col[y].lower_bound(x)))+1);
			sum+=x-nx;
			dir=(dir+1)%4;
			left=y;
		}
		if(nx==x&&ny==y)
			break;
		x=nx;y=ny;
	}
	puts((sum+k==n*m)?"Yes":"No");
	return 0;
}