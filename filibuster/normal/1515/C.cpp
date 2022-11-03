#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 311;

mt19937 rnd(0);

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    set<pii> st;
    for(int i = 0; i < m; i++) {
        st.insert({0, i});
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;

        int j = st.begin()->s, a = st.begin()->f;
        st.erase(st.begin());
        ans[i] = j;
        st.insert({a + y, j});
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << ' ';
    cout << endl;

}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}