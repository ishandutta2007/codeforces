#pragma comment (linker, "/STACK:10000000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>
  
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort
 
using namespace std;
 

int c, d, n, m, k, ans = 0;

int main()
{
	cin >> c >> d >> n >> m >> k;
	int s = n * m;
	s -= k;
	ans += min((s / n) * c, d * (s - s % n));
	s %= n;
	ans += min(c, d * s);
	cout << max(0, ans) << '\n';

}