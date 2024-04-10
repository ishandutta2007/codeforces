//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
vector<P1>data[7005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int t; scanf("%d",&t);
		if(t==1)
		{
			int dep,lb,ub,val;
			scanf("%d %d %d %d",&dep,&lb,&ub,&val);
			data[dep].pb(mp(val,mp(lb,ub)));
		}
		else
		{
			int dep,id; scanf("%d %d",&dep,&id);
			int lb=id,ub=id;
			set<int>zip;
			for(int j=dep;j<=n;j++)
			{
				for(int k=0;k<data[j].size();k++)
				{
					if(!(ub<data[j][k].s.f || data[j][k].s.s<lb))
					{
						zip.insert(data[j][k].f);
					}
				}
				int a=-1,b=-1,gen=1;
				for(int ii=0;;ii++)
				{
					if(gen>=lb && a==-1) a=ii;
					if(gen>ub && b==-1) b=ii;
					if(a!=-1 && b!=-1) break;
					gen*=2;
				}
				lb+=a; ub+=b;
			}
			printf("%d\n",zip.size());
		}
	}
}