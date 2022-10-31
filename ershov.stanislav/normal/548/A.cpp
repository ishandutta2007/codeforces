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

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

string s;
int k;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> s >> k;
    bool flag = true;
    if ((int) s.length() % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int) s.length() / k; j++) {
            if (s[j + i * (int) s.length() / k] != s[(i + 1) * (int) s.length() / k - j - 1]) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}