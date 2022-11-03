#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*
1
3
1 1 1
*/

int n;
int a[N];
int cnt[N], c[N];
int b[N];

bool is(int x) {
    set<pii> st;
    for(int i = 0; i < n; i++) {
        st.insert({-cnt[i], i});
        c[i] = cnt[i];
    }

    for(int i = 0; i < n; i++) {
        if(st.empty()) {
            return false;
        }

        int a1 = st.begin()->s;

        if(c[a1] == 0)
            return false;

        st.erase(st.begin());
        c[a1]--;
        b[i] = a1;

        if(i >= x && c[b[i - x]] > 0) {
            st.insert({-c[b[i - x]], b[i - x]});
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cnt[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];

        a[i]--;

        cnt[a[i]]++;
    }

    int l = 0, r = n;
    while(r - l > 1) {
        int m = (l + r) / 2;

        if(is(m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}