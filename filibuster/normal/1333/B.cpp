#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int M = 1e9 + 7;
const int INF = 1e9;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    map<int, int> mp;
    for(int i = 0; i< n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    for(int i = 0; i< n; i++) {
        cin >> b[i];
    }

    for(int i = n - 1; i >= 0; i--) {
        mp[a[i]]--;
        if(a[i] == b[i])
            continue;

        if(a[i] < b[i]) {
            if(mp[1] == 0) {
                cout << "NO" << endl;
                return;
            }
        } else  {
            if(mp[-1] == 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t = 1;
    cin >> t;

    while(t--)
        solve();
}