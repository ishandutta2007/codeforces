#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int a[26];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 0, m; cin >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i], n += a[i];
    if (n%2 == 1) {
        for (int i = n; i > 0; i -= 2) {
            bool v = 1;
            int c = 0;
            for (int j = 0; j < m; j++) {
                v = v && a[j]%i == 0;
                if (a[j]%(2*i) != 0) c++;
            }
            if (v && c == 1) {
                for (int j = 0; j < m; j++)
                    if (a[j]%(2*i) != 0) c = j;
                cout << i << "\n";
                for (int j = 0; j < i; j++) {
                    cout << char(c+'a');
                    for (int k = 0; k < m; k++)
                        for (int r = 0; r < (a[k]-(k == c ? i : 0))/(2*i); r++)
                            cout << char('a'+k);
                    for (int k = m-1; k >= 0; k--)
                        for (int r = 0; r < (a[k]-(k == c ? i : 0))/(2*i); r++)
                            cout << char('a'+k);
                }
                cout << "\n";
                return 0;
            }
        }
    } else {
        for (int i = n; i > 0; i -= 2) {
            bool v = 1;
            for (int j = 0; j < m; j++)
                v = v && a[j]%i == 0;
            if (v) {
                cout << i << "\n";
                for (int j = 0; j < i/2; j++) {
                    for (int k = 0; k < m; k++)
                        for (int r = 0; r < a[k]/i; r++)
                            cout << char('a'+k);
                    for (int k = m-1; k >= 0; k--)
                        for (int r = 0; r < a[k]/i; r++)
                            cout << char('a'+k);
                }
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "0\n";
    for (int i = 0; i < m; i++)
        while (a[i]--) cout << char('a'+i);
    cout << "\n";
}