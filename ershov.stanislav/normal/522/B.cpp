#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#define PROBLEM "B"

const int N = 200500;
int h[N], w[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#else
//  assert(freopen(PROBLEM".in", "r", stdin) != NULL);
//  assert(freopen(PROBLEM".out", "w", stdout));
#endif

    int n;
    cin >> n;
    int mx1 = -INF, mx2 = -INF, sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &w[i], &h[i]);
        if (h[i] >= mx1) {
            mx2 = mx1;
            mx1 = h[i];
        }
        else if (h[i] > mx2) {
            mx2 = h[i];
        }
        sum += w[i];
    }

    for (int i = 0; i < n; ++i) {
        int cur_w = sum - w[i];
        int cur_h = (h[i] == mx1 ? mx2 : mx1);
        printf("%d ", cur_w * cur_h);
    }
    cout << endl;
    return 0;
}