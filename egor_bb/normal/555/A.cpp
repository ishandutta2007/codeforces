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


ll n, k, pos[100005], ans = 0;

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n >> k;
	vector <vector <int> > v;
	v.resize(k);
	for (int i = 0; i < k; i++){
		int t; cin >> t;
		ans += t - 1;
		v[i].resize(t);
		for (int j = 0; j < t; j++){
			cin >> v[i][j];
			pos[v[i][j]] = i;
		}
	}
	ans += n - 1;
	int cnt = 1;
	for (int i = 1; i < v[pos[1]].size(); i++){
		if (v[pos[1]][i] - 1 != v[pos[1]][i - 1]) break;
		cnt++;
	}
	ans -= 2 * (cnt - 1);
	cout << ans << '\n';
}