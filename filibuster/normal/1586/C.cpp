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

    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> st;
    for(int j = 0; j < m - 1; j++) {
        for(int i = 1; i < n; i++) {
            if(a[i][j] == 'X' && a[i - 1][j + 1] == 'X') {
                st.insert(j);
                break;
            }
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        auto it = st.lower_bound(l);

        cout << (it == st.end() || *it >= r - 1 ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();

}