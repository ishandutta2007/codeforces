#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    li l, r;
    cin >> l >> r;

    l--;

    li s = 0;
    for(int i = 0; i < n; i++) {
        li s1 = s + 2 * (n - i - 1);

        li lf = max(l, s);
        li rg = min(r, s1);

//        cout <<"seeg " << lf << ' ' << rg << endl;

        for(li j = lf - s; j < rg - s; j++) {
            if(j % 2 == 0) {
                cout << i + 1 << ' ';
            } else {
                cout << i + j / 2 + 2 << ' ';
            }
        }

        s = s1;
    }

    if(r == n * 1ll * (n - 1) + 1) {
        cout << 1;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}