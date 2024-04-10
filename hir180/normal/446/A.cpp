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
#define INF 1000000001
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int r[100005];
vector<int>pos;
int x[100005];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(i!=1)
		{
			if(x[i-1] >= x[i]) pos.pb(i-1);
		}
	}
	int res = 0;
	for(int i=1;i<=n;i++)
	{
		int lb=i;
		int ub=n+1;
		int a = lower_bound(pos.begin(),pos.end(),i)-pos.begin();
		while(ub-lb>1)
		{
			int mid = (lb+ub)/2;
			int b = lower_bound(pos.begin(),pos.end(),mid)-pos.begin();
			int c = b-a;
			if(c == 0)
			{
				lb = mid;
			}
			else if(c == 1)
			{
				if(pos[a] == mid-1 || pos[a]==i)
				{
					lb = mid;
				}
				else if(x[pos[a]]+2 <= x[pos[a]+2] || x[pos[a]-1]+2<=x[pos[a]+1])
				{
					lb = mid;
				}
				else
				{
					ub = mid;
				}
			}
			else if(c >= 2)
			{
				ub = mid;
			}
		}
		res = max(res,lb-i+1);
	}
	cout << res << endl;
}