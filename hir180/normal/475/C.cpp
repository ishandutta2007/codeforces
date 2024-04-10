#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
char f[2105][2105];
int rui[1005][1005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&f[i]);
	}
	P p = mp(INF,INF);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(f[i][j] == 'X')
			{
				if(p.fi > i || (p.fi == i && p.sc > j))
				{
					p = mp(i,j);
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			rui[i+1][j+1] = rui[i+1][j]+rui[i][j+1]-rui[i][j]+(f[i][j] == 'X');
		}
	}
	int x=n-1,y=m-1;
	for(int i=p.fi+1;i<n;i++)
	{
		if(f[i][p.sc] != 'X')
		{
			 x = i-1; break;
		}
	}
	for(int i=p.sc+1;i<m;i++)
	{
		if(f[p.fi][i] != 'X')
		{
			 y = i-1; break;
		}
	}
	vector<P>vec;
	int res = INF;
	for(int i=p.sc;i<=y;i++) vec.pb(mp(x-p.fi+1,i-p.sc+1));
	for(int i=p.fi;i<=x;i++) vec.pb(mp(i-p.fi+1,y-p.sc+1));
	for(int i=0;i<vec.size();i++)
	{
		int curx = p.fi,cury = p.sc;
		int sum = 0;
		int prev = -1;
		while(sum != rui[n][m])
		{
			if(rui[curx+vec[i].fi][cury+vec[i].sc]-rui[curx+vec[i].fi][cury]-rui[curx][cury+vec[i].sc]+rui[curx][cury] != vec[i].fi*vec[i].sc)
			{
				goto out;
			}
			if(sum == 0) sum += vec[i].fi*vec[i].sc;
			else if(prev == 0) sum += vec[i].fi;
			else if(prev == 1) sum += vec[i].sc;
			if(sum == rui[n][m]) break;
			if(f[curx+vec[i].fi][cury] == 'X' && f[curx][cury+vec[i].sc] == 'X') goto out;
			if(f[curx+vec[i].fi][cury] != 'X' && f[curx][cury+vec[i].sc] != 'X') goto out;
			if(f[curx+vec[i].fi][cury] == 'X')
			{
				prev = 1; curx++;
			}
			else
			{
				prev = 0; cury++;
			}
		}
		res = min(res,vec[i].fi*vec[i].sc);
		out:;
	}
	if(res == INF) res = -1;
	cout << res << endl;
}