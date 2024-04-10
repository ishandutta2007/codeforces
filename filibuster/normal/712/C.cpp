#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
5 10
99.99
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int x, y;
    cin >> x >> y;

    if(x > y)
        swap(x, y);

    int a = x, b = x, c = x;

    int ans = 0;
    while(true) {
        if(a == y && b == y && c == y) {
            cout << ans;
            return 0;
        }

//        cout << a << ' ' << b << ' ' << c << endl;

        vector<int> z = {a, b, c};
        sort(z.begin(), z.end());

        a = z[0], b = z[1], c = z[2];

        if(x < y)
            a = min(b + c - 1, y);
        else
            c = max(abs(b - a) + 1, y);
        ans++;
    }
}