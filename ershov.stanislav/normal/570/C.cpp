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
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 3e5 + 100;

int n, m, cnt;
char s[N];
set<int> st;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    scanf(" %s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            cnt++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '.' && (i == 0 || s[i - 1] != '.')) {
            st.insert(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int x;
        char c;
        scanf(" %d %c", &x, &c);
        x--;
        if (s[x] != '.' && c == '.') {
            s[x] = '.';
            cnt++;
            if (x == 0 || s[x - 1] != '.') {
                st.insert(x);
            }
            if (x < n - 1 && s[x + 1] == '.') {
                st.erase(x + 1);
            }
        }
        if (s[x] == '.' && c != '.') {
            s[x] = c;
            cnt--;
            if (x == 0 || s[x - 1] != '.') {
                st.erase(x);
            }
            if (x < n - 1 && s[x + 1] == '.') {
                st.insert(x + 1);
            }
        }
        printf("%d\n", cnt - (int) st.size());
    }
    return 0;
}