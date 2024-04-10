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

bool used[26];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int k;
    string s;
    cin >> k >> s;

    vector<string> v;

    for (int i = 0; i < s.length(); i++) {
        if (!used[s[i] - 'a']) {
            used[s[i] - 'a'] = true;
            v.pb("");
        }
        v.back().pb(s[i]);
    }

    if (v.size() < k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++) {
            cout << v[i] << endl;
        }
        for (int i = k - 1; i < v.size(); i++) {
            cout << v[i];
        }
    }

    return 0;
}