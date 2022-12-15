#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;

const int SIZE  = 1 << 8;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

int main() {
    ll a, b, x, y, z;
    cin >> a >> b >> x >> y >> z;
    cout << max(0ll, x * 2 + y - a) + max(0ll, y + z * 3 - b) << endl;
	return 0;
}