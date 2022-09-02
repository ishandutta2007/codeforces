#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int p[10][2],g[10][2];
int n,m,k,s;
int main()
{
	cin >> n >> m >> k >> s;
	for(int i=0;i<10;i++)
	{
		p[i][0]=g[i][0]=100000;
		p[i][1]=g[i][1]=-100000;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;
			cin >> x;
			int f=i+j;
			int h=i-j;
			p[x][0]=min(p[x][0],f);
			p[x][1]=max(p[x][1],f);
			g[x][0]=min(g[x][0],h);
			g[x][1]=max(g[x][1],h);
		}
	}
	int ret=0;
	int rev=-1;
	for(int i=0;i<s;i++)
	{
		int f; cin >> f;
		if(rev==-1){ rev=f; continue;}
		ret=max(ret,p[rev][1]-p[f][0]);
		ret=max(ret,p[f][1]-p[rev][0]);
		ret=max(ret,g[rev][1]-g[f][0]); 
		ret=max(ret,g[f][1]-g[rev][0]);
		
		rev=f;
	}

	cout << ret << endl;
}