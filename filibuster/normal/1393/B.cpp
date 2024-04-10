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
aaaaaaaaa
aaaaaaaaaa

aaaaaababc
*/

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    set<pii> st;
    st.insert({0, 1});
    st.insert({0, 2});
    st.insert({0, 3});
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        st.erase({-mp[x], x});
        mp[x]++;
        st.insert({-mp[x], x});
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        char c;
        int y;
        cin >> c >> y;

        st.erase({-mp[y], y});
        if(c == '+')
            mp[y]++;
        else
            mp[y]--;
        st.insert({-mp[y], y});

        int x = st.begin()->s;
        if(mp[x] < 4) {
            cout << "NO" << endl;
            continue;
        }

        st.erase({-mp[x], x});
        st.insert({-mp[x] + 4, x});

        auto it = st.begin();
        if(it->f <= -4) {
            cout << "YES" << endl;
        } else {
            it++;
            if(it->f <= -2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

        st.erase({-mp[x] + 4, x});
        st.insert({-mp[x], x});
    }
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}