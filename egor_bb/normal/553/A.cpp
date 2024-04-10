#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;

using namespace std;


ll d[1005][1005], k, c[1005];

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> k;
	for (int i = 0; i < k; i++) cin >> c[i];
	d[0][0] = 1;
	for (int i = 1; i < 1005; i++){
		d[i][0] = 1;
		for (int j = 1; j < 1005; j++){
			d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % INF;
		}
	}
	ll ans = 1, got = 0;
	for (int i = 0; i < k; i++){
		ans = (ans * d[got  + c[i] - 1][c[i] - 1]) % INF;
		got += c[i];
	}
	cout << ans << '\n';
}