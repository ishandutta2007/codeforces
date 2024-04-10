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
#define sqr 350
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

ll beg[300];
ll cur[300];
ll gen[300];
bool all[300];
int ov[300];
int col[100005];
int bel[100005];
vector<int>cpy[300];
ll rui[300][355];
ll lazyall[300];
ll lazy[100005];
ll last[300];
int n,m;
//i...sqr*(i-1)+1...sqr*i
//1-index
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		col[i] = i;
		bel[i] = (i+sqr-1)/sqr;
		beg[bel[i]] += i;
		cur[bel[i]] += i;
		cpy[bel[i]].pb(i);
	}
	for(int a=bel[1];a<=bel[n];a++)
	{
		for(int i=0;i<cpy[a].size();i++)
		{
			if(i == 0) rui[a][i] = 1LL*cpy[a][cpy[a].size()-1-i];
			else rui[a][i] = rui[a][i-1] + 1LL*cpy[a][cpy[a].size()-1-i];
		}
	}
	for(int i=0;i<m;i++)
	{
		int t; scanf("%d",&t);
		if(t == 1)
		{
			int l,r,c;
			scanf("%d %d %d",&l,&r,&c);
			for(int a = bel[l];a <= bel[r];a++)
			{
				//a
				//indexj
				if(a == bel[l] || a == bel[r])
				{
					if(all[a])
					{
						for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++)
						{
							if(col[j] > last[a])
							{
								lazy[j] += col[j] - last[a];
							}
						}
						for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++) col[j] = ov[a];
						all[a] = false; last[a] = -1;
					}
					for(int j=max(l,sqr*(a-1)+1);j<=min(r,sqr*a);j++)
					{
						cur[a] += c-col[j];
						if(c < col[j])
						{
							gen[a] += col[j]-c;
							lazy[j] += col[j]-c;
						}
						col[j] = c;
					}
					for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++)
					{
						cpy[a][j-sqr*(a-1)-1] = col[j];
					}
					sort(cpy[a].begin(),cpy[a].end());
					for(int i=0;i<cpy[a].size();i++)
					{
						if(i == 0) rui[a][i] = cpy[a][cpy[a].size()-1-i];
						else rui[a][i] = rui[a][i-1] + cpy[a][cpy[a].size()-1-i];
					}
				}
				else
				{
					if(!all[a])
					{
						all[a] = true; last[a] = c;
						ov[a] = c;
						cur[a] = 1LL* ( min(n,sqr*a) - (sqr*(a-1)+1) + 1) * c;
						int d = upper_bound(cpy[a].begin(),cpy[a].end(),c) - cpy[a].begin();
						if(d != cpy[a].size())
						{
							gen[a] += rui[a][cpy[a].size()-1-d] - 1LL*c*(cpy[a].size()-d);
						}
					}
					else
					{
						if(ov[a] > c)
						{
							gen[a] += 1LL* ( min(n,sqr*a) - (sqr*(a-1)+1) + 1) * (ov[a]-c);
							lazyall[a] += (ov[a]-c);
						}
						ov[a] = c;
						cur[a] = 1LL* ( min(n,sqr*a) - (sqr*(a-1)+1) + 1) * c;
					}
				}
			}
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);
			ll res = 0;
			for(int a = bel[l];a <= bel[r];a++)
			{
				if(a == bel[l] || a == bel[r])
				{
					if(all[a])
					{
						for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++)
						{
							if(col[j] > last[a])
							{
								lazy[j] += col[j] - last[a];
							}
						}
						for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++) col[j] = ov[a];
						all[a] = false; last[a] = -1;
					}
					for(int j=max(l,sqr*(a-1)+1);j<=min(r,sqr*a);j++)
					{
						res += col[j] - j + (lazy[j]+lazyall[a])*2LL;
						
					}
					for(int j=sqr*(a-1)+1;j<=min(n,sqr*a);j++)
					{
						cpy[a][j-sqr*(a-1)-1] = col[j];
					}
					sort(cpy[a].begin(),cpy[a].end());
					for(int i=0;i<cpy[a].size();i++)
					{
						if(i == 0) rui[a][i] = cpy[a][cpy[a].size()-1-i];
						else rui[a][i] = rui[a][i-1] + cpy[a][cpy[a].size()-1-i];
					}
				}
				else
				{
					res += cur[a]-beg[a]+gen[a]*2LL;
				}
			}
			printf("%lld\n",res);
		}
	}
}