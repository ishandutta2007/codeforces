#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

/*
2 1 9
1 2 1
*/

int a[N];
int d[N];
int lf[N], rg[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
        d[i] = abs(a[i] - a[i - 1]);
    }

    lf[1] = 0;
    stack<int> st;
    st.push(1);
    for(int i = 2; i < n; i++) {
        while(!st.empty() && d[st.top()] < d[i])
            st.pop();

        if(st.empty())
            lf[i] = 0;
        else
            lf[i] = st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    for(int i = n - 1; i > 0; i--) {
        while(!st.empty() && d[st.top()] <= d[i])
            st.pop();

        if(st.empty())
            rg[i] = n;
        else
            rg[i] = st.top();

        st.push(i);
    }

//    for(int i = 1; i < n; i++) {
//        cout << i << ' ' << d[i] << ' ' << lf[i] << ' ' << rg[i] << endl;
//    }

    for(int j = 0; j < q; j++) {
        int l, r;
        cin >> l >> r;

        l--;

        if(r - l == 1) {
            cout << 0 << endl;
            continue;
        }

        li res = 0;

        for(int i = l + 1; i < r; i++) {
            int l1 = max(l, lf[i]);
            int r1 = min(r, rg[i]);

//            cout << i << ' ' << l1 << ' ' << r1 << endl;

            res += (r1 - i) * 1ll * (i - l1) * d[i];
        }

        cout << res << endl;
    }
}