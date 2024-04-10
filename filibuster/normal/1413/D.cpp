#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >> n;

    vector<pii> a(n * 2);
    for(int i = 0; i < n * 2; i++) {
        char c;
        cin >> c;

        if(c == '+') {
            a[i] = {1, -1};
        } else {
            a[i].f = 0;
            cin >> a[i].s;
            a[i].s--;
        }
    }

    stack<int> st;
    vector<int> b(2 * n);
    vector<pair<pii, int>> c(n);
    for(int i = 0; i < 2 * n; i++) {
        if(a[i].f == 1)
            continue;

        while(!st.empty() && a[st.top()].s < a[i].s)
            st.pop();

        b[i] = (st.empty() ? -1 : st.top());
        st.push(i);

        c[a[i].s] = {{b[i] + 1, i}, a[i].s};
    }
//
//    for(int i = 0; i < n; i++) {
//        cout << i << ' ' << c[i].f.f << ' ' << c[i].f.s << endl;
//    }

    sort(c.begin(), c.end());



    set<pii> s;
    int j = 0;
    vector<int> ans;
    for(int i = 0; i < n * 2; i++) {
        while(j < c.size() && c[j].f.f <= i) {
            s.insert({c[j].f.s, c[j].s});
            j++;
        }

//        cout << "i " << i << endl;
//        for(auto p : s)
//            cout << p.f << ' ' << p.s << endl;

        if(a[i].f == 1) {
            if(s.empty() || s.begin()->f <= i) {
                cout << "NO" << endl;
                return 0;
            }

            ans.push_back(s.begin()->s);
            s.erase(s.begin());
        }
    }


    cout << "YES" << endl;
    for(auto x : ans)
        cout << x + 1 << ' ';
}