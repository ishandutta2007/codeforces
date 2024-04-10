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
#define rank _rank

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

const int N = 1e5 + 100;

int a[N], n;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        while (a[i] % 2 == 0) {
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }
    }
    bool flag = true;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != a[i + 1]) {
            flag = false;
        }
    }
    if (flag) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}