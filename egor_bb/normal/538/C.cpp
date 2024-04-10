#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const int SZ = 70;
const double eps = 1e-15;

using namespace std;




int n, m, lst = 0, bst = 0, h, d, ld;

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n >> m;
	cin >> d >> h;
	lst = h; ld = d;
	bst = d - 1 + h;
	for (int i = 1; i < m; i++){
		cin >> d >> h;
		if (abs(h - lst) > abs(d - ld)){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		bst = max(bst, max(h, lst) + ((d - ld) - abs(h - lst)) / 2);
		lst = h; ld = d;
	}
	bst = max(bst, lst + n - ld);
	cout << bst << '\n';
}