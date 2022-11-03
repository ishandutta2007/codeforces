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



void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pii> a;
    for(int i = 0; i < n; ) {
        int j = i;
        while(s[i] == s[j])
            j++;
        a.emplace_back(s[i] == 'L' ? 0 : 1, j - i);
        i = j;
    }

    if(a.back().f == a[0].f && a.size() >= 2) {
        a[0].s += a.back().s;
        a.pop_back();
    }

    if(a.size() == 1) {
        cout << (n + 2) / 3 << endl;
    } else {
        int ans = 0;
        for(int i = 0; i < a.size(); i++)
            ans += (a[i].s / 3);
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();

}