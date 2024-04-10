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

const int N = 1e5 + 100;

struct point {
    int x, y;
    int i;
    point (int x = 0, int y = 0) : x(x), y(y) {}
};

bool operator<(const point & a, const point & b) {
    return a.y < b.y;
}

vector<point> v[1100];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        point p;
        scanf("%d%d", &p.x, &p.y);
        p.i = i;
        v[p.x / 1000].pb(p);
    }
    int cnt = 0;
    for (int i = 0; i < 1010; i++) {
        sort(all(v[i]));
        if (i % 2 == 1) {
            reverse(all(v[i]));
        }
        for (int j = 0; j < (int) v[i].size(); j++) {
            cnt++;
            printf("%d%c", v[i][j].i, " \n"[cnt == n]);
        }
    }
    return 0;
}