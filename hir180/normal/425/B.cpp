//IOI2014
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
#define mod 1000000007
#define geta 100000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int v[105][105],h,w,lim;
int t[105][105];
int main()
{
	cin >> h >> w >> lim;
	if(h >= w)
	{
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&v[i][j]);
			}
		}
	}
	else
	{
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				scanf("%d",&v[j][i]);
			}
		}
		swap(h,w);
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<w;j++)
		{
			t[i][j] = v[i][j] != v[i][j+1];
			
		}
	}
	int x[105];
	if(h > lim)
	{
		int res=INF;
		for(int cpy=1;cpy<=h;cpy++)
		{
			int tot=0;
			for(int i=1;i<=h;i++)
			{
				int pl=INF;
				for(int mask = 0; mask < 4;mask++)
				{
					for(int j=1;j<w;j++) x[j] = t[i][j];

					int ope=0;
					if(mask&1) x[1] ^= 1, ope++;
					if(mask&2) x[w-1] ^= 1, ope++;
					for(int j=1;j<w-1;j++)
					{
						if(x[j] != t[cpy][j])
						{
							ope++;
							x[j]^=1;
							x[j+1]^=1;
						}
					}
					for(int j=1;j<w;j++) if(x[j] != t[cpy][j]) {ope=INF; break;}
					pl = min(pl,ope);
				}
				tot = min(tot+pl,INF);
			}
			res = min(res,tot);
		}
		cout << (res<=lim?res:-1) << endl;
	}
	else
	{
		int res=INF;
		for(int mask=0;mask<(1<<(w-1));mask++)
		{
			int d[15];
			for(int j=0;j<w-1;j++) d[j+1] = (((mask >> j)&1));
			
			int tot=0;
			for(int i=1;i<=h;i++)
			{
				int pl=INF;
				for(int mask = 0; mask < 4;mask++)
				{
					for(int j=1;j<w;j++) x[j] = t[i][j];

					int ope=0;
					if(mask&1) x[1] ^= 1, ope++;
					if(mask&2) x[w-1] ^= 1, ope++;
					for(int j=1;j<w-1;j++)
					{
						if(x[j] != d[j])
						{
							ope++;
							x[j]^=1;
							x[j+1]^=1;
						}
					}
					for(int j=1;j<w;j++) if(x[j] != d[j]) {ope=INF; break;}
					pl = min(pl,ope);
				}
				tot = min(tot+pl,INF);
			}
			res = min(res,tot);
		}
		cout << (res<=lim?res:-1) << endl;
	}
}