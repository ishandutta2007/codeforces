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
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;

        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<bool> b(n, false);
    int x = -1, y = -1;
    for(int i = 0; i < n; i++) {
        bool fl = false;
        for(int j = 0; j < a[i].size(); j++)
            if(!b[a[i][j]]) {
                b[a[i][j]] = true;
                fl = true;
                break;
            }

        if(!fl)
            x = i;
    }

    if(x == -1) {
        cout << "OPTIMAL" << endl;
        return ;
    }

    for(int i = 0; i < n; i++)
        if(!b[i]) {
            y = i;
            break;
        }

    cout << "IMPROVE" << endl << x + 1 << ' ' << y + 1 << endl;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}