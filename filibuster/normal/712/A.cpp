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

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
//        s2 += a[i];
    }

    vector<int> b(n);

//    b[0] = (a[0] + s) / 2;
    li s1 = 0, s2 = 0;
    for(int i = n - 1; i >= 0; i--) {
        if((n - i) % 2 == 0) {
            b[i] = a[i] + s1 - s2;
//            s1 -= b[i];
            s2 += b[i];
        } else {
            b[i] = a[i] - s1 + s2;
//            s2 -= b[i];
            s1 += b[i];
        }

    }

    for(auto x : b)
        cout << x << ' ';
}