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

const int N = 1e6+100;

char s[1111], t[N];
int m, n;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf(" %s %s", s, t);
    m = strlen(s);
    n = strlen(t);

    int mn1 = 0, mn2 = n - 1, i, j;
    for (i = 0, j = 0; i < n && j < m; i++) {
        if (t[i] == s[j]) {
            j++;
        }
    }
    mn1 = i;
    for (i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
        if (t[i] == s[j]) {
            j--;
        }
    }
    mn2 = i;

    cout << max(0, mn2 - mn1 + 2) << endl;
    return 0;
}