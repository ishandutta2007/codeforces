//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
char f[105][10005];
vector<int>zip[105];
int main()
{
	srand((unsigned int)time(NULL));
	int w,h; cin >> h >> w;
	for(int i=0;i<h;i++)
	{
		scanf("%s",f[i]);
		for(int j=0;j<w;j++)
		{
			if(f[i][j]=='1') zip[i].pb(j);
		}
		if(zip[i].empty())
		{
			puts("-1");  return 0;
		}
	}
	int ret=INF;
	for(int j=0;j<w;j++)
	{
		int tot=0;
		for(int i=0;i<h;i++)
		{
			int minv=INF;
			int s=lower_bound(zip[i].begin(),zip[i].end(),j)-zip[i].begin();
			for(int k=max(0,s-5);k<=min(s+5,(int)zip[i].size()-1);k++)
			{
				minv=min(minv,min(abs(zip[i][k]-j),w-abs(zip[i][k]-j)));
			}
			minv=min(minv,min(abs(zip[i][zip[i].size()-1]-j),w-abs(zip[i][zip[i].size()-1]-j)));
			minv=min(minv,min(abs(zip[i][0]-j),w-abs(zip[i][0]-j)));
			tot+=minv;
		}
		ret=min(ret,tot);
	}
	cout << ret << endl;
}