#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    ll x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    ll foot = abs(x - y) * t1;
    ll elev = abs(x - z) * t2 + abs(x - y) * t2 + 3 * t3;
    cout << (foot < elev ? "NO" : "YES") << endl;
}