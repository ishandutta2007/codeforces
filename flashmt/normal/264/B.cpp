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

int n, a[100100], longest[100100];
vector <int> divisor[100100];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 2; i <= 100000; i++)
		if (divisor[i].empty())
			for (int j = i; j <= 100000; j += i)
				divisor[j].push_back(i);
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int best = 0;
		for (int j = 0; j < int(divisor[a[i]].size()); j++)
			best = max(best, longest[divisor[a[i]][j]]);
		ans = max(ans, ++best);
		for (int j = 0; j < int(divisor[a[i]].size()); j++)
			longest[divisor[a[i]][j]] = best;
	}
	cout << ans << endl;
}