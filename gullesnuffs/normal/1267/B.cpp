#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    char last = 0;
    int lastco = 0;
    vector<pii> parts;
    trav(x, s) {
        if (x != last) {
            if (lastco)
                parts.emplace_back(last, lastco);
            last = x;
            lastco = 0;
        }
        lastco++;
    }
    parts.emplace_back(last, lastco);
    if (sz(parts) % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    rep(i,0,sz(parts) / 2) {
        int j = sz(parts)-1 - i;
        if (parts[i].first != parts[j].first || parts[i].second + parts[j].second < 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    int i = sz(parts) / 2;
    if (parts[i].second < 2) {
        cout << 0 << endl;
        return 0;
    }
    cout << parts[i].second + 1 << endl;
}