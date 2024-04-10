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

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    int n;
    string s, t;
    cin >> n;
    cin >> s >> t;
    int i = 0;
    for (; i < s.length(); i++) {
        if (s[i] != t[i]) {
            break;
        }
    }

    string r1 = s.substr(0, i) + t[i] + s.substr(i, s.length() - i);
    string r2 = t.substr(0, i) + s[i] + t.substr(i, s.length() - i);

//    cout << r1 << ' ' << r2 << endl;

    int cnt = 0;
    i = 0;
    int j = n;
    while (i < n && r1[i] == t[i]) {
        i++;
    }
    while (j > 1 && r1[j] == t[j - 1]) {
        j--;
    }
    if (j <= i) {
        cnt++;
    }
    i = 0;
    j = n;
    while (i < n && r2[i] == s[i]) {
        i++;
    }
    while (j > 1 && r2[j] == s[j - 1]) {
        j--;
    }
    if (j <= i) {
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}