#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second

int h,w,q;
int le[1005][1005];
int ri[1005][1005];
int up[1005][1005];
int down[1005][1005];
int s[1005][1005];

int main()
{
	scanf("%d%d%d",&h,&w,&q);
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			scanf("%d",&s[i][j]);
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(s[i][j-1]) le[i][j] = le[i][j-1]+1;
			else le[i][j] = 0;
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=w;j>=1;j--)
		{
			if(s[i][j+1]) ri[i][j] = ri[i][j+1]+1;
			else ri[i][j] = 0;
		}
	}
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(s[j-1][i]) up[j][i] = up[j-1][i]+1;
			else up[j][i] = 0;
		}
	}
	for(int i=1;i<=w;i++)
	{
		for(int j=h;j>=1;j--)
		{
			if(s[j+1][i]) down[j][i] = down[j+1][i]+1;
			else down[j][i] = 0;
		}
	}
	
	for(int i=0;i<q;i++)
	{
		int op,x,y;
		scanf("%d %d %d",&op,&x,&y);
		if(op == 1)
		{
			s[x][y] = 1-s[x][y];
			for(int i=x;i<=x;i++)
			{
				for(int j=1;j<=w;j++)
				{
					if(s[i][j-1]) le[i][j] = le[i][j-1]+1;
					else le[i][j] = 0;
				}
			}
			for(int i=x;i<=x;i++)
			{
				for(int j=w;j>=1;j--)
				{
					if(s[i][j+1]) ri[i][j] = ri[i][j+1]+1;
					else ri[i][j] = 0;
				}
			}
			for(int i=y;i<=y;i++)
			{
				for(int j=1;j<=h;j++)
				{
					if(s[j-1][i]) up[j][i] = up[j-1][i]+1;
					else up[j][i] = 0;
				}
			}
			for(int i=y;i<=y;i++)
			{
				for(int j=h;j>=1;j--)
				{
					if(s[j+1][i]) down[j][i] = down[j+1][i]+1;
					else down[j][i] = 0;
				}
			}
		}
		else
		{
			int a = INF,b = INF,res = 0;
			for(int i=x;i<=h;i++)
			{
				if(!s[i][y]) break;
				a = min(a,le[i][y]);
				b = min(b,ri[i][y]);
				res = max(res,(i-x+1)*(a+b+1));
			}
			a = INF,b = INF;
			for(int i=x;i>=1;i--)
			{
				if(!s[i][y]) break;
				a = min(a,le[i][y]);
				b = min(b,ri[i][y]);
				res = max(res,(x-i+1)*(a+b+1));
			}
			a = INF,b = INF;
			for(int i=y;i<=w;i++)
			{
				if(!s[x][i]) break;
				a = min(a,up[x][i]);
				b = min(b,down[x][i]);
				res = max(res,(i-y+1)*(a+b+1));
			}
			a = INF,b = INF;
			for(int i=y;i>=1;i--)
			{
				if(!s[x][i]) break;
				a = min(a,up[x][i]);
				b = min(b,down[x][i]);
				res = max(res,(y-i+1)*(a+b+1));
			}
			printf("%d\n",res);
		}
	}
}