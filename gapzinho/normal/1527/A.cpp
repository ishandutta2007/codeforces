#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;



int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int k = 1;
        while(k*2 <= n) {
            k*=2;
        }
        cout << k-1 << endl;
    }
    return 0;
}