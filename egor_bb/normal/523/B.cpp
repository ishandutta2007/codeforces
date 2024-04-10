#pragma comment (linker, "/STACK:10000000000")

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <deque>
#include <cassert>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <map>
#include <string>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define sort stable_sort
#define psi pair<string, int>
#define pll pair<ll, ll>
#define problem "test"


using namespace std;


ll n, t, a[200005], m, p[200005], sum[200005];
double c, f[200005];


int main(){
//	ifstream cin (problem".in");
	cout.precision(8);
	cin >> n >> t >> c;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) cin >> p[i];
	for (int i = 1; i <= n; i++){
		f[i] = (f[i - 1] + a[i - 1] * 1. / t) * 1. / c;
	}
	for (int i = 0; i < m; i++){
		cout << fixed << (sum[p[i]] - sum[p[i] - t]) * 1. / t << " " << f[p[i]] << " " <<	abs(f[p[i]] - (sum[p[i]] - sum[p[i] - t]) * 1. / t ) * 1. / ((sum[p[i]] - sum[p[i] - t]) * 1. / t ) << '\n';
	}	
}