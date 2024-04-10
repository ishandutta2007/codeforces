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
    string s;
    cin >> s;
    set<string> magic;
    for (int i = 0; i <= s.length(); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            magic.insert(s.substr(0, i) + c + s.substr(i));
        }
    }
    cout << magic.size() << endl;
    return 0;
}