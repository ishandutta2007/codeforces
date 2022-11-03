#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 998244353;
const int N = 3013;

void solve() {
    int n;
    cin >> n;

    for(int i = 30; i >= 0; i--) {
        if((1 << i) & n) {
            cout << ((1 << i) - 1) << endl;
            return;
        }
    }

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}