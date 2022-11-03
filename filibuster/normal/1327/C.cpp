#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

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
    int n, m;
    cin >> n >> m;

    string s = "";

    for(int i = 0; i < n - 1; i++) {
        s += "D";
    }

    for(int i = 0; i < m - 1; i++) {
        s += "L";
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            s +=  (i % 2 == 0 ? 'R' : 'L');
        }
        if(i < n - 1)
            s += 'U';
    }

    cout << s.size() << endl << s;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}