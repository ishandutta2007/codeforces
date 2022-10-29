#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <queue>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000000001;
const int INF = 1E9;
const int MAXN = 110000;

int n, k, d[MAXN], ad[MAXN];
long double a[MAXN], b[MAXN], t, h;
vector<pair<pair<long double, long double>, int> > w;

bool get(long double t) {
    int cur = 1;
    long double ch;
    forn(i, n) {
        if (cur > k) break;
        ch = h * cur;
        if (ch / w[i].fi.se <= t + eps) {
            ad[cur - 1] = w[i].se;
            cur++;
        }
    }
    if (cur > k) {
        forn(i, k)
            d[i] = ad[i];
        return 1;
    }
    return 0;
}

long double binarnik() {
    int iter = 1;
    long double l = 0, r = INF, m;
    while (iter <= 300) {
        m = (l + r) / 2;
        if (get(m))
            r = m;
        else
            l = m;
        iter++;
    }
    return r;
}

int main() {

    cin >> n >> k >> h;
    forn(i, n)
        cin >> a[i];
    forn(i, n)
        cin >> b[i];
    forn(i, n)
        w.push_back(make_pair(make_pair(a[i], b[i]), i + 1));
    
    sort(all(w));
    t = binarnik();
    get(t);
    
    forn(i, k)
        cout << d[i] << ' ';
    cout << '\n';

    return 0;
}