#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <queue>
 
using namespace std;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char f[2005][2005];
bool u[2005][2005];
queue<P>que;
bool ch(int i,int j)
{
	int dx[4] = {0,1,0,-1};
	int dy[4] = {-1,0,1,0};
	int cnt = 0;
	for(int k=0;k<4;k++)
	{
		int x = i+dx[k];
		int y = j+dy[k];
		if(!(0<=x && x<n)) continue;
		if(!(0<=y && y<m)) continue;
		if(!u[x][y]) cnt++;
	}
	if(cnt == 1) return true;
	else return false;
}
vector<pair<P,P> >res;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&f[i]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(f[i][j] == '*') u[i][j] = true;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!u[i][j] && ch(i,j)) que.push(mp(i,j));
	while(!que.empty())
	{
		P p = que.front(); que.pop();
		if(u[p.fi][p.sc]) continue;
		
		if(p.sc+1 < m && !u[p.fi][p.sc+1])
		{
			res.pb(mp(p,mp(p.fi,p.sc+1)));
			u[p.fi][p.sc] = true;
			u[p.fi][p.sc+1] = true;
			if(p.sc-1 >= 0 && !u[p.fi][p.sc-1] && ch(p.fi,p.sc-1))  que.push(mp(p.fi,p.sc-1));
			if(p.sc+2 < m && !u[p.fi][p.sc+2] && ch(p.fi,p.sc+2))  que.push(mp(p.fi,p.sc+2));
			if(p.fi-1 >= 0 && !u[p.fi-1][p.sc] && ch(p.fi-1,p.sc)) que.push(mp(p.fi-1,p.sc));
			if(p.fi-1 >= 0 && !u[p.fi-1][p.sc+1] && ch(p.fi-1,p.sc+1)) que.push(mp(p.fi-1,p.sc+1));
			if(p.fi+1 < n && !u[p.fi+1][p.sc] && ch(p.fi+1,p.sc)) que.push(mp(p.fi+1,p.sc));
			if(p.fi+1 < n && !u[p.fi+1][p.sc+1] && ch(p.fi+1,p.sc+1)) que.push(mp(p.fi+1,p.sc+1));
		}
		if(p.sc-1 >= 0 && !u[p.fi][p.sc-1])
		{
			res.pb(mp(p,mp(p.fi,p.sc-1)));
			u[p.fi][p.sc] = true;
			u[p.fi][p.sc-1] = true;
			if(p.sc-2 >= 0 && !u[p.fi][p.sc-2] && ch(p.fi,p.sc-2))  que.push(mp(p.fi,p.sc-2));
			if(p.sc+1 < m && !u[p.fi][p.sc+1] && ch(p.fi,p.sc+1))  que.push(mp(p.fi,p.sc+1));
			if(p.fi-1 >= 0 && !u[p.fi-1][p.sc] && ch(p.fi-1,p.sc)) que.push(mp(p.fi-1,p.sc));
			if(p.fi-1 >= 0 && !u[p.fi-1][p.sc-1] && ch(p.fi-1,p.sc-1)) que.push(mp(p.fi-1,p.sc-1));
			if(p.fi+1 < n && !u[p.fi+1][p.sc] && ch(p.fi+1,p.sc)) que.push(mp(p.fi+1,p.sc));
			if(p.fi+1 < n && !u[p.fi+1][p.sc-1] && ch(p.fi+1,p.sc-1)) que.push(mp(p.fi+1,p.sc-1));
		}
		if(p.fi+1 < n && !u[p.fi+1][p.sc])
		{
			res.pb(mp(p,mp(p.fi+1,p.sc)));
			u[p.fi][p.sc] = true;
			u[p.fi+1][p.sc] = true;
			if(p.fi-1 >= 0 && !u[p.fi-1][p.sc] && ch(p.fi-1,p.sc))  que.push(mp(p.fi-1,p.sc));
			if(p.fi+2 < n && !u[p.fi+2][p.sc] && ch(p.fi+2,p.sc))  que.push(mp(p.fi+2,p.sc));
			if(p.sc-1 >= 0 && !u[p.fi][p.sc-1] && ch(p.fi,p.sc-1)) que.push(mp(p.fi,p.sc-1));
			if(p.sc-1 >= 0 && !u[p.fi+1][p.sc-1] && ch(p.fi+1,p.sc-1)) que.push(mp(p.fi+1,p.sc-1));
			if(p.sc+1 < m && !u[p.fi][p.sc+1] && ch(p.fi,p.sc+1)) que.push(mp(p.fi,p.sc+1));
			if(p.sc+1 < m && !u[p.fi+1][p.sc+1] && ch(p.fi+1,p.sc+1)) que.push(mp(p.fi+1,p.sc+1));
		}
		if(p.fi-1 >= 0 && !u[p.fi-1][p.sc])
		{
			res.pb(mp(p,mp(p.fi-1,p.sc)));
			u[p.fi][p.sc] = true;
			u[p.fi-1][p.sc] = true;
			if(p.fi-2 >= 0 && !u[p.fi-2][p.sc] && ch(p.fi-2,p.sc))  que.push(mp(p.fi-2,p.sc));
			if(p.fi+1 < n && !u[p.fi+1][p.sc] && ch(p.fi+1,p.sc))  que.push(mp(p.fi+1,p.sc));
			if(p.sc-1 >= 0 && !u[p.fi][p.sc-1] && ch(p.fi,p.sc-1)) que.push(mp(p.fi,p.sc-1));
			if(p.sc-1 >= 0 && !u[p.fi-1][p.sc-1] && ch(p.fi-1,p.sc-1)) que.push(mp(p.fi-1,p.sc-1));
			if(p.sc+1 < m && !u[p.fi][p.sc+1] && ch(p.fi,p.sc+1)) que.push(mp(p.fi,p.sc+1));
			if(p.sc+1 < m && !u[p.fi-1][p.sc+1] && ch(p.fi-1,p.sc+1)) que.push(mp(p.fi-1,p.sc+1));
		}
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!u[i][j]) { puts("Not unique"); return 0; }
	for(int i=0;i<res.size();i++)
	{
		if(res[i].fi.fi == res[i].sc.fi)
		{
			f[res[i].fi.fi][min(res[i].fi.sc,res[i].sc.sc)] = '<';
			f[res[i].fi.fi][max(res[i].fi.sc,res[i].sc.sc)] = '>';
		}
		else
		{
			f[min(res[i].fi.fi,res[i].sc.fi)][res[i].fi.sc] = '^';
			f[max(res[i].fi.fi,res[i].sc.fi)][res[i].fi.sc] = 'v';
		}
	}
	for(int i=0;i<n;i++) printf("%s\n",f[i]);
}