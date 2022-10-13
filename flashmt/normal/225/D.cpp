#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};

int m,n,k,f[15000000];
queue < int > q;
vector < pii > snake(10);
string s[22];

int valid(vector < pii > snake,int x,int y)
{
	if (x<0 || y<0 || x>=m || y>=n || s[x][y]=='#') return 0;
	fr(i,1,k-2)
		if (snake[i]==mp(x,y)) return 0;
	return 1;
}
	
vector < pii > move(vector < pii > snake,int dir)
{
	int x=snake[0].fi,y=snake[0].se;
	vector < pii > res;
	if (!valid(snake,x+dx[dir],y+dy[dir])) return res;
	res.pb(mp(x+dx[dir],y+dy[dir]));
	fr(i,0,k-2) res.pb(snake[i]);
	return res;
}

int direction(pii u,pii v)
{
	if (u.fi==v.fi) return u.se<v.se?1:3;
	return u.fi<v.fi?2:0;
}

int encode(vector < pii > snake)
{
	int res=snake[0].fi*15+snake[0].se;
	fr(i,1,k-1) res=(res<<2)+direction(snake[i-1],snake[i]);
	return res;
}

void decode(vector < pii > &snake,int K)
{
	int d[10];
	rep(i,k-1) d[i]=K&3, K>>=2;
	snake[0].se=K%15; snake[0].fi=K/15;
	repp(i,k-1) 
	{
		snake[k-1-i].fi=snake[k-2-i].fi+dx[d[i]];
		snake[k-1-i].se=snake[k-2-i].se+dy[d[i]];
	}
}

int main()
{
	cin >> m >> n;
	rep(i,m) cin >> s[i];

	rep(i,m) rep(j,n)
		if (s[i][j]>='1' && s[i][j]<='9')
		{
			int x=s[i][j]-'0';
			k=max(k,x);
			snake[x-1]=mp(i,j);
		}
	snake.resize(k);
		
	int v=encode(snake);
	f[v]=1;
	q.push(v);
	while (!q.empty())
	{
		v=q.front(); q.pop();
		decode(snake,v);
		if (s[snake[0].fi][snake[0].se]=='@')
		{
			cout << f[v]-1 << endl;
			return 0;
		}
		
		rep(i,4)
		{
			vector < pii > newSnake=move(snake,i);
			if (newSnake.empty()) continue;
			int u=encode(newSnake);
			if (!f[u]) f[u]=f[v]+1, q.push(u);
		}
	}
	
	puts("-1");
}