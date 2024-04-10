#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>



using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

typedef long long tint;

#define all(c) (c).begin(), (c).end()
#define esta(x,c) ((c).find(x) != (c).end())

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> v(m);
	tint s = 0;
	forn(i,m) 
	{
		cin >> v[i].first;
		s += v[i].first;
		v[i].second = i;
	}
	if (s < n)
	{
		cout << "-1\n";
		return 0;
	}
	//sort(all(v), greater<pair<int,int>>());
	vector<int> ret(m);
	int pos = 0;
	forn(i,m)
	{
		int L = v[i].first;
		pos = int(max(tint(pos), n-s));
		if (n-pos < L)
		{
			cout << "-1\n";
			return 0;
		}
		ret[v[i].second] = pos;
		s -= L;
		pos++;
	}
	forn(i,m)
	{
		if (i) cout << " ";
		cout << ret[i]+1;
	}
	cout << "\n";
	return 0;
}