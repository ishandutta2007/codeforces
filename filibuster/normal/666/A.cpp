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

int getl(int l) {
    return (l == 2 ? 3 : 2);
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();

    s += "0000000000";

    if(n <= 6) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 7) {
        cout << 1 << endl << s.substr(5, 2) << endl;
        return 0;
    }

    if(n == 8) {
        vector<string> a = {s.substr(5, 3), s.substr(6, 2)};
        sort(a.begin(), a.end());
        cout << 2 << endl << a[0] << endl << a[1] << endl;
        return 0;
    }

    set<string> st1;
    vector<vector<bool>> dp(n + 5, vector<bool>(5, false));
//    dp[n] = dp[n - 2] = dp[n - 3] = true;
    dp[n][2] = dp[n][3] = dp[n - 2][2] = dp[n - 3][3] = true;
    st1.insert(s.substr(n - 2, 2));
    st1.insert(s.substr(n - 3, 3));
    for(int i = n - 4; i >= 5; i--) {
        for(int l = 2; l <= 3; l++) {
            if(s.substr(i, l) != s.substr(i + l, l) && dp[i + l][l] ||
                dp[i + l][getl(l)]) {
                    dp[i][l] = true;
                    st1.insert(s.substr(i, l));
                }

//            if(i + l * 2 <= n) {
//                if(s.substr(i, l) != s.substr(i + l, l) && dp[i + l * 2] ||
//                   dp[i + 5])
//                    dp[i] = true;
//            }

        }
    }

//    set<pii> st;
//    st.insert({n - 2, 2});
//    st.insert({n - 3, 3});
//    if(s.substr(n - 4, 2) != s.substr(n - 2, 2))
//        st.insert({n - 4, 2});
//
////    cout << "sg" << endl;
//    for(int i = n - 5; i >= 5; i--) {
//        for(int l = 2; l <= 3; l++) {
//            if(s.substr(i, l) != s.substr(i + l, l) || !dp[n + l * 2])//n - i - 2 * l == 1)
//                st.insert({i, l});
//        }
//    }


//    for(auto p : st)
//        st1.insert(s.substr(p.f, p.s));

    cout << st1.size() << endl;
    for(auto x : st1)
        cout << x << endl;
}