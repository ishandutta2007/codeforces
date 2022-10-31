#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define ll long long
#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "movetofront"

const int INF = int(1e9);
const ll INFll = ll(1e12) + 7;
const int SZ = 70;

using namespace std;

ll a[100005], n, l, r = INFll, mx;

int main(){
//	ifstream cin (problem".in");
//	ofstream cout(problem".out");
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	l = mx - 1;
	while (r - l > 1){
		ll m = (l + r) / 2, got = 0;
		for (int i = 0; i < n; i++){
			got += m - a[i];
		}
		if (got >= m) r = m;
		else l = m;
	}
	cout << r << '\n';
}