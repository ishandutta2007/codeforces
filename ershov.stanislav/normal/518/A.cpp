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

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    cin >> s >> t;
    int n = s.length();

    int add = 1;
    int i = n - 1;
    while (add) {
        if (s[i] < 'z') {
            s[i]++;
            add = 0;
        } else {
            s[i] = 'a';
        }
        i--;
    }
    if (s < t) {
        cout << s << endl;
    } else {
        cout << "No such string" << endl;
    }
    return 0;
}