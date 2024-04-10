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

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

string s, t;

int cnt1[128], cnt2[128];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    for (int i = 0; i < n; i++) {
        cnt1[s[i]]++;
    }
    for (int i = 0; i < m; i++) {
        cnt2[t[i]]++;
    }

    int a = 0, b = 0;
    for (int i = 0; i < 128; i++) {
        int c = min(cnt1[i], cnt2[i]);
        cnt1[i] -= c;
        cnt2[i] -= c;
        a += c;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        int c = min(cnt1[i], cnt2[i + 'A' - 'a']);
        cnt1[i] -= c;
        cnt2[i + 'A' - 'a'] -= c;
        b += c;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        int c = min(cnt1[i], cnt2[i + 'a' - 'A']);
        cnt1[i] -= c;
        cnt2[i + 'a' - 'A'] -= c;
        b += c;
    }
    cout << a << ' ' << b << endl;
    return 0;
}