#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool flag = true;
            for (int k = i, cnt = 0; cnt < 5; k += j - i, cnt++) {
                if (k >= n || s[k] != '*') {
                    flag = false;
                }
            }
            if (flag) {
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "no\n";
    return 0;
}