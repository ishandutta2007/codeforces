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
#define maxN 1
using namespace std;
const long long oo = 1LL << 60;

int n, c[100100], v[100100];
long long f[100100];


int main()
{
	int Q;
	long long A, B;
	cin >> n >> Q;
	for (int i = 1; i <= n; i++) scanf("%d", v + i);
	for (int i = 1; i <= n; i++) scanf("%d", c + i);
	while (Q--)
	{
		cin >> A >> B;
		for (int i = 0; i <= 100000; i++) f[i] = -oo;
		long long ans = 0;
		pair <long long,int> max1 = make_pair(-oo, 0), max2 = make_pair(-oo, 1);
		
		for (int i = 1; i <= n; i++)
		{
			long long best = max(B * v[i], A * v[i] + f[c[i]]);
			if (max1.second != c[i]) best = max(best, max1.first + B * v[i]);
			else best = max(best, max2.first + B * v[i]);
			f[c[i]] = max(f[c[i]], best);
			ans = max(ans, best);
			if (best > max1.first)
			{
				if (max1.second == c[i]) max1.first = best;
				else max2 = max1, max1 = make_pair(best, c[i]);
			}
			else
				if (best > max2.first)
				{
					if (max1.second != c[i]) max2 = make_pair(best, c[i]);
				}
		}
		cout << ans << endl;
	}
}