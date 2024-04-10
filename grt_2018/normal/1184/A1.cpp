//GRT_2018
#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll r;
	cin >> r;
	if(r % 2 == 0 || r < 5) {
		cout << "NO\n";
	} else {
		cout << "1 " << (r - 3) / 2 << "\n";
	}
}