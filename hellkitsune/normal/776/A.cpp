#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string a, b;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    cin >> n;
    cout << a << ' ' << b << '\n';
    forn(i, n) {
        string s;
        cin >> s;
        if (s == a) {
            cin >> a;
        } else {
            cin >> b;
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}