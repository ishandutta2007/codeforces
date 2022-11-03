#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 14;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> st;
    for(int i = n - 1; i >= 0; i--) {
        if(st.count(a[i] + 1)) {
            st.insert(a[i]);
        } else {
            st.insert(a[i] + 1);
        }
    }

    cout << st.size() << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }
}