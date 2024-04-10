#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')')
            cnt++;
        else
            break;
    }

    if(cnt > n - cnt) {
        cout << "Yes" << endl;
    } else
        cout << "No" <<endl;
}

int main() {

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}