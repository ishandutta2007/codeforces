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
int t[2][200005];
int rui[100005];
int main()
{
	for(int i=0;i<2;i++) for(int j=0;j<200005;j++) t[i][j] = INF;
	int n;
	cin >> n;
	int a = 0,b = 0;
	for(int i=0;i<n;i++)
	{
		int x; cin >> x;
		rui[i+1] = rui[i]+(x==1);
		if(x == 1)
		{
			a++;
			t[0][a] = i;
		}
		else
		{
			b++;
			t[1][b] = i;
		}
	}
	vector<P>vec;
	for(int a=1;a<=n;a++)
	{
		int curx = 0,cury = 0;
		int gx = 0,gy = 0;
		while(1)
		{
			int d = min(t[0][curx+a],t[1][cury+a]);
			if(d == INF) break;
			int px = gx,py = gy;
			if(t[0][curx+a] < t[1][cury+a]) gx++;
			else gy++;
			
			curx = rui[d+1];
			cury = d+1-rui[d+1];
			if(d == n-1)
			{
				if(px >= py && gx > px) vec.pb(mp(max(gx,gy),a));
				if(px <= py && gy > py) vec.pb(mp(max(gx,gy),a));
				break;
			}
		}
	}
	cout << vec.size() << endl; sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++) cout << vec[i].fi << " " << vec[i].sc << endl;
}