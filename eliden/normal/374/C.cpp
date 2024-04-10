#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 2e3;
char a[sz][sz];
char s[4] = {'D','I','M','A'};
int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};
bool done[sz][sz], live[sz][sz];
int dep[sz][sz];
int n,m;
int depth(int i,int j)
{
	if(done[i][j])
		return dep[i][j];
	else if(live[i][j])
	{
		dep[i][j] = -1;
		return -1;
	}
	dep[i][j] =1;
	live[i][j] = true;
	int w=-1;
	rep(k,0,4)
		if(s[k]==a[i][j])
			w = k;
	rep(k,0,4)
	{
		int ii=i+di[k], jj=j+dj[k];
		if(ii>=0 && ii<n && jj>=0 && jj<m)
			if(a[ii][jj]==s[(w+1)%4])
			{
				int d = depth(ii,jj);
				if(d==-1)
					dep[i][j] = -1;
				else if(dep[i][j]!=-1 && d+1>dep[i][j])
					dep[i][j] = d+1;
			}
	}
	live[i][j] = false;
	done[i][j] = true;
	return dep[i][j];
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,0,n)
		scanf("%s",a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			done[i][j] = false;
			live[i][j] = false;
		}
	int maxdepth = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j]==s[0])
			{
				int d = depth(i,j);
				if(d==-1)
					maxdepth=-1;
				else if(maxdepth!=-1 && d>maxdepth)
					maxdepth = d;
			}
	if(maxdepth==-1)
		printf("Poor Inna!\n");
	else
	{
		maxdepth/=4;
		if(maxdepth==0)
			printf("Poor Dima!\n");
		else
			printf("%d\n",maxdepth);
	}
}