#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int K = 10;

/*
2 1 9
1 2 1
*/

void solve() {
    string s;
    cin >> s;

    vector<int> a;
    char lst = '0';
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            if(lst == '1')
                a.back()++;
            else
                a.push_back(1);
        }
        lst = s[i];
    }

    sort(a.begin(), a.end());

//    for(auto x : a)
//        cout << x << ' ';
//    cout << endl;

    int ans = 0;
    for(int i = a.size() - 1; i >= 0; i -= 2)
        ans += a[i];

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