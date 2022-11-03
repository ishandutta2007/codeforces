#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 5000;
const int A = 1e6 + 13;

/*
3
177650 578041 907590

329549 45091

*/

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> mp;
    for(auto x : s)
        mp[x]++;

    if(mp['<'] == 0 || mp['>'] == 0) {
        cout << n << endl;
        return;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '-' || s[(i + 1) % n] == '-')
            ans++;
    }

    cout << ans << endl;

//    vector<vector<int>> g(n), r(n);
//    for(int i = 0; i < n; i++) {
//        int j = (i + 1) % n;
//        if(s[i] == '>')
//            g[i].push_back(j);
//        else if(s[i] == '<')
//            g[j].push_back(i);
//        else {
//
//        }
//
//    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}