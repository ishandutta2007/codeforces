#include <vector>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>

#define INF 1000000009
#define INFl 1000000000000000007
#define ll long long
#define mp make_pair
#define pb push_back

using namespace std;


int n, k, f[2005];


int main(){
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> f[i];
	sort (f, f + n);
	for (int i = n - 1; i >= 0; i -= k) ans += (f[i] - 1) * 2;
	cout << ans;
}