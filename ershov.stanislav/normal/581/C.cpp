#include<bits/stdc++.h>

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

const int N = 5e5 + 100;

int n, k;
int a[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    int cur = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        cur += a[i] / 10;
        if (a[i] < 100) v.pb(10 - (a[i] % 10));
    }
    sort(all(v));
    reverse(all(v));
    while (v.size() && k >= v.back()) {
        k -= v.back();
        cur++;
        v.pop_back();
    }
    while (cur < n * 10 && k >= 10) {
        cur++;
        k -= 10;
    }
    cout << cur << endl;
    return 0;
}