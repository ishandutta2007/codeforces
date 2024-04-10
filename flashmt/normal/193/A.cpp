#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int m,n,painted,d[55][55];
string a[55];

int dfs(int x,int y)
{
	if (x<0 || y<0 || x>=m || y>=n || a[x][y]=='.' || d[x][y]) return 0;
	d[x][y]=1;
	for (int i=0;i<4;i++) dfs(x+dx[i],y+dy[i]);
	return 1;
}

int main()
{
	cin >> m >> n;
	for (int i=0;i<m;i++) cin >> a[i];
	
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (a[i][j]=='#')
			{
				painted++;
				a[i][j]='.';
				
				memset(d,0,sizeof(d));
				int region=0;
				for (int k=0;k<4;k++) region+=dfs(i+dx[k],j+dy[k]);				
				if (region>1) 
				{
					puts("1"); return 0;
				}
				
				a[i][j]='#';					
			}
	
	puts(painted<3?"-1":"2");	
}