#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;
using pli = pair<li, li>;
using vi = vector<int>;
using vli = vector<li>;
using vpli = vector<pli>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;


    if(n % 2 != k % 2) {
        cout << "NO" << endl;
        return;
    }

    li s = k * 1ll * k;

    cout << (s <= n ? "YES" : "NO") << endl;

}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}