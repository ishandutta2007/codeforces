#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int N = 1e6 + 13;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<int> ans;

    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == b[i])
            continue;

        if(b[i] == a[0])
            ans.push_back(1);

        ans.push_back(i + 1);
        reverse(a.begin(), a.begin() + i + 1);
        for(int j = 0; j < i; j++)
            a[j] = (a[j] == '0' ? '1' : '0');
    }

    cout << ans.size() << ' ';
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}