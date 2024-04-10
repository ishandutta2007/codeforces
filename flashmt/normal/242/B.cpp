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

pair < pair<int,int>,int > a[100100];

int main()
{
	int x,y,n;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> x >> y;
		a[i]=make_pair(make_pair(x,-y),i);
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
		if (-a[i].first.second>-a[1].first.second)
		{
			puts("-1");
			return 0;
		}
	cout << a[1].second << endl;
}