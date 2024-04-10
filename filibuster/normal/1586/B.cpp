//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define x first
//#define y second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
//using matr

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;
const int B = 600;
const int A = 256;
const ld e = 1e-8;
const int LOGN = 20;

mt19937 rnd(time(0));


void solve() {
    int n, m;
    cin >> n >> m;

    vector<bool> a(n, false);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        y--;

        a[y] = true;
    }

    int v = -1;
    for(int i = 0; i < n; i++)
        if(!a[i])
            v = i;

    for(int i = 0; i < n; i++) {
        if(i != v)
            cout << v + 1 << ' ' << i + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}