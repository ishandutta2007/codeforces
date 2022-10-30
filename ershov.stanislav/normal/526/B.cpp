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

using namespace std;

long long a[111000];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    long long ans = 0;
    for (int i = 0; i < ((1 << (n + 1)) - 2); i++) {
        cin >> a[i + 2];
    }
    for (int i = (1 << (n + 1)) - 2; i >= 2; i-=2) {
        ans += abs(a[i] - a[i + 1]);
        a[i] = max(a[i], a[i + 1]);
        a[i  + 1] = max(a[i], a[i + 1]);
        a[i / 2] += a[i];
    }
    cout << ans << endl;
    return 0;
}