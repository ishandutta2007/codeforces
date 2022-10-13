#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

vector < pair<string,int> > a;
map <string,bool> b;

int main()
{
	//freopen("a.in.0","r",stdin);
	string s;
	int x,m,n;
	double k;
	cin >> n >> m >> k;
	while (n--)
	{
		cin >> s >> x;
		x=int(k*x+1e-8);
		if (x>=100) a.pb(mp(s,x)), b[s]=1;
	}
	while (m--)
	{
		cin >> s;
		if (!b[s]) a.pb(mp(s,0)), b[s]=1;
	}
	if (!a.empty()) sort(a.begin(),a.end());
	cout << a.size() << endl;
	fr(x,0,int(a.size())-1) cout << a[x].first << " " << a[x].second << endl;
	return 0;
}