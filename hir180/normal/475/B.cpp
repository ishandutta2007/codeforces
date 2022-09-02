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
int main()
{
	int n,m;
	string a,b;
	cin >> n >> m >> a >> b;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			queue<P>que;
			bool used[25][25]={};
			que.push(mp(i,j));
			while(!que.empty())
			{
				P p = que.front(); que.pop();
				if(used[p.fi][p.sc]) continue;
				used[p.fi][p.sc] = true;
				if(a[p.fi] == '>')
				{
					for(int a=p.sc+1;a<m;a++)
					{
						if(!used[p.fi][a])
						{
							que.push(mp(p.fi,a));
						}
					}
				}
				else
				{
					for(int a=p.sc-1;a>=0;a--)
					{
						if(!used[p.fi][a])
						{
							que.push(mp(p.fi,a));
						}
					}
				}
				if(b[p.sc] == 'v')
				{
					for(int a=p.fi+1;a<n;a++)
					{
						if(!used[a][p.sc])
						{
							que.push(mp(a,p.sc));
						}
					}
				}
				else
				{
					for(int a=p.fi-1;a>=0;a--)
					{
						if(!used[a][p.sc])
						{
							que.push(mp(a,p.sc));
						}
					}
				}
			}
			for(int a=0;a<n;a++)
			{
				for(int b=0;b<m;b++)
				{
					if(!used[a][b]) goto out;
				}
			}
		}
	}
	puts("YES"); return 0;
	out:; puts("NO");
}