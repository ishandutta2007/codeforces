#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
//#define DEBUG
//#define RANDOM
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<ll> > cnt(n + 1, vector<ll>(4, 0));
	cnt[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int nw = 0; nw < 3; nw++)
		{
			// novy znak
			if (s[i] != '?' && s[i] != nw + 'a')
			{
				continue;
			}
			cnt[i + 1][nw + 1] += cnt[i][nw];
			cnt[i + 1][nw + 1] %= mod;
		}
		for (int nw = 0; nw < 4; nw++)
		{
			if (s[i] == '?')
			{
				// mohli sme mat viac moznosti na tento znak
				// ale nie vsetky sa pripocitali
				// 
				cnt[i + 1][nw] += cnt[i][nw] * 3;
			}
			else
			{
				cnt[i + 1][nw] += cnt[i][nw];
			}
			cnt[i + 1][nw] %= mod;
		}
	}
	cout << cnt[n][3] << "\n";
	return 0;
}