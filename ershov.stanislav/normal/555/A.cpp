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

const int N = 1e5 + 100;

int n, k;
int cnt = 0;
int a[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", a + j);
        }
        int k = 0;
        if (a[0] == 1) while (k + 1 < m && a[k + 1] == a[k] + 1) {
            k++;
        }
        cnt += m - k - 1;
        cnt += m - k;
    }
    cnt--;
    cout << cnt << endl;
    return 0;
}