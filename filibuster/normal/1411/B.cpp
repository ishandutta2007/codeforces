#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;

void solve() {
    li n;
    cin >> n;

    for(li x = n; ; x++) {
        li y = x;
        bool res = true;
        while(y > 0) {
            int c = y % 10;
            if(c != 0 && x % c != 0) {
                res = false;
                break;
            }
            y /= 10;
        }
        if(res) {
            cout << x <<endl;
            break;
        }
    }
}

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}