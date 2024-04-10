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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n;
vector<int> v;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        v.pb(a - n + i);
    }
    sort(all(v));
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            flag = false;
        }
    }
    if (flag) {
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i] + n - i);
        }
    } else {
        printf(":(");
    }
    return 0;
}