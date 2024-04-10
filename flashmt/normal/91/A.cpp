#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

char a[10010],b[1000100];
int m,n,re,next[10010][30];
vector <int> c[200];

int main()
{
	//freopen("a.in.1","r",stdin);
	int i,j,x,y;
	scanf("%s",&a); m=strlen(a);
	scanf("%s",&b); n=strlen(b);
	memset(next,-1,sizeof(next));
	fr(i,0,m-1) 
	{
		x=a[i]-'a';
		fr(j,0,25)
			if (!c[j].empty())
			{
				int u=c[j].size()-1;
				while (u>=0)
				{
					y=c[j][u];
					if (next[y][x]!=-1) break;
					next[y][x]=i;
					u--;
				}
			}
		c[x].pb(i);
	}
	fr(x,0,25)
		if (!c[x].empty())
		{
			i=c[x][0];
			fr(j,0,25)
				if (!c[j].empty())
				{
					int u=c[j].size()-1;
					while (u>=0)
					{
						y=c[j][u];
						if (next[y][x]!=-1) break;
						next[y][x]=i;
						u--;
					}
				}
		}
	x=b[0]-'a';
	if (c[x].empty()) cout << "-1" << endl;
	else
	{
		y=c[x][0]; re=1;
		fr(i,1,n-1)
		{
			x=b[i]-'a';
			j=next[y][x];
			if (j<0) 
			{
				cout << "-1" << endl; 
				return 0;
			}
			if (j<=y) re++;
			y=j;
		}
		cout << re << endl;
	}
	return 0;
}