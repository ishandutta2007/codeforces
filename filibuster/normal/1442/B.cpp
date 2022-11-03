#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 998244353;
const int N = 2e5 + 13;
const int B = 350;

int t[N];
int n;

void upd(int i, int x) {
    for(; i <= n; i = (i | (i + 1)))
        t[i] += x;
}

int get(int i) {
    int res = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

int get(int l, int r) {
    return get(r) - (l > 0 ? get(l - 1) : 0);
}

void solve() {
    int k;
    cin >> n >> k;

    vector<int> a(n), ind(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        ind[a[i]] = i;
    }

    vector<int> b(k);
    for(int i = 0; i < k; i++) {
        cin >> b[i];
        b[i]--;
    }

    set<int> st;
    for(auto x : b)
        st.insert(x);

    for(int i = 0; i <= n; i++) {
        t[i] = 0;
    }

    int ans = 1;
    for(auto x : b) {
        int i = ind[x];
        int res = 0;
        if(get(i + 1, n - 1) < n - i - 1 && st.count(a[i + 1]) == 0)
            res++;
        if(get(0, i - 1) < i && st.count(a[i - 1]) == 0)
            res++;

        ans = ans * 1ll * res % M;
        st.erase(x);
    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}