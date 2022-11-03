#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 10013;
const int A = 513;


/*
*/

int main() {
    int n, y;
    li x;
    cin >> n >> x >> y;

    vector<int> a(n, 1);
    a[0] = y - n + 1;
    if(a[0] * 1ll * a[0] + n - 1 >= x && y >= n) {
        for(auto x : a)
            cout << x << '\n';
    } else {
        cout << -1 << endl;
    }
}