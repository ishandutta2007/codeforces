#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int INF = 1e9 + 13;
const int N = 2e5 + 13;
const int M = 1e9 + 7;

/*

*/

int get(vi a, vi b) {
    int n = a.size(), m = b.size();

    set<int> st;
    map<int, int> ind;
    for(int i = 0; i < m; i++) {
        st.insert(b[i]);
        ind[b[i]] = i;
    }

    vector<int> is(n);
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(st.count(a[i])) {
            res++;
            is[i] = 1;
        } else {
            is[i] = 0;
        }
    }

    int cur = res;
    int j = 0;
    for(int i = 0; i < n; i++) {
        int k = i + 1;
        int nxt = (i < n - 1 ? a[i + 1] : INF);
        cur -= is[i];

        while(j < m && b[j] < a[i])
            j++;

        for(; j < m && b[j] < nxt; j++) {
            int x = *st.lower_bound(b[j] - k + 1);
            res = max(res, cur + j - ind[x] + 1);
        }
    }

    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a1, a2, b1, b2;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x < 0)
            a2.push_back(-x);
        else
            a1.push_back(x);
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if(x < 0)
            b2.push_back(-x);
        else
            b1.push_back(x);
    }

    reverse(a2.begin(), a2.end());
    reverse(b2.begin(), b2.end());

    cout << get(a1, b1) + get(a2, b2) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}