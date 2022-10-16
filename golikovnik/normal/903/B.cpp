#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define endl '\n'
#define X first
#define Y second

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int h1, a1, c1;
    cin >> h1 >> a1 >> c1;
    int h2, a2;
    cin >> h2 >> a2;
    int hh1 = h1;
    vector<int> ans;
    int turn = 0;
    while (h2 > 0) {
        if (turn == 0) {
        if (h2 - a1 <= 0) {
            ans.pb(0);
            h2 -= a1;
            turn = 1 - turn;
            continue;
        }
        if (hh1 - a2 <= 0) {
            ans.pb(1);
            hh1 += c1;
            turn = 1 - turn;
            cerr << hh1 << endl;
            continue;
        }
        ans.pb(0);
        h2 -= a1;
        } else {
            hh1 -= a2;
        }
        turn = 1 - turn;
    }
    cout << ans.size() << endl;
    for (auto &x: ans) {
        if (x) {
            cout << "HEAL" << endl;
        } else {
            cout << "STRIKE" << endl;
        }
    }
    return 0;
}