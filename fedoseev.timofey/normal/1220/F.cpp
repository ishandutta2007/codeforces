#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 7;

int mx[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            pos = i;
        }
    }
    vector <int> st;
    vector <int> resR(n), resL(n);
    st.push_back(a[pos]);
    int cur = pos;
    for (int i = 0; i + 1 < n; ++i) {
        ++cur;
        cur %= n;
        int curmx = 0;
        while (st.back() > a[cur]) {
            curmx = max(curmx, mx[st.size() - 1]);
            st.pop_back();
            ++curmx;
        }
        st.push_back(a[cur]);
        resR[cur] = curmx + (int)st.size() - 1;
        resR[cur] = max(resR[cur], resR[(cur - 1 + n) % n]);
        mx[(int)st.size() - 1] = curmx;
    }
    for (int i = 0; i < N; ++i) mx[i] = 0;
    st.clear();
    st.push_back(a[pos]);
    cur = pos;
    for (int i = 0; i + 1 < n; ++i) {
        --cur;
        cur = (cur + n) % n;
        int curmx = 0;
        while (st.back() > a[cur]) {
            curmx = max(curmx, mx[st.size() - 1]);
            st.pop_back();
            ++curmx;
        }
        st.push_back(a[cur]);
        resL[cur] = curmx + (int)st.size() - 1;
        resL[cur] = max(resL[cur], resL[(cur + 1) % n]);
        mx[(int)st.size() - 1] = curmx;
    }
    int best = 1e9, shift = -1;
    for (int i = 0; i < n; ++i) {
        int cur = max(resL[i] + 1, resR[(i - 1 + n) % n] + 1);
        if (cur < best) {
            best = cur;
            shift = i;
        }
    }
    cout << best << ' ' << shift << '\n';
}