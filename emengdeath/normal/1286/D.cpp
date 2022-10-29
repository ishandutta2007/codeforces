#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e5;
const int mod = 998244353;
bool forbid[N][2][2];
struct node{
    int v[2][2];
    void clear(){
        memset(v, 0, sizeof(v));
    }
}f[N * 4], w;
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int sub(int x, int y) {
    return ((x - y) % mod + mod) % mod;
}
int n;
int x[N], v[N], p[N];
vector<pair<int, pair<int, int> > > d;
ll calc(ll x, ll y){
    ll z = 1;
    while (y) {
        if (y & 1) z = z * x % mod;
        x = x * x % mod, y /= 2;
    }
    return z;
}
void combine(node&a, node b, node c, int mid) {
    a.clear();
    for (int i = 0; i < 2; i ++)
        for (int j = 0; j < 2; j ++)
            if (!forbid[mid][i][j])
                for (int ii = 0; ii < 2; ii ++)
                    for (int jj = 0; jj < 2; jj ++)
                        a.v[ii][jj] = add(a.v[ii][jj], mul(b.v[ii][i], c.v[j][jj]));
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].v[0][0] =sub(1, p[l]);
        f[s].v[1][1] = p[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    combine(f[s], f[s+s],f[s+s+1], (l + r)/ 2);
}
long double gett_double(pair<int, pair<int, int> > a) {
    long double speed = abs((a.second.second == a.second.first)? v[a.first] - v[a.first + 1]:v[a.first] + v[a.first + 1]);
    return (x[a.first + 1] - x[a.first]) / speed;
}
int gett_int(pair<int, pair<int, int> > a) {
    int speed = abs((a.second.second == a.second.first)? v[a.first] - v[a.first + 1]:v[a.first] + v[a.first + 1]) % mod;
    return mul((x[a.first + 1] - x[a.first]) % mod, calc(speed ,mod - 2));
}
void get(int l, int r, int s, int ll, int rr ){
    if (rr < l || r < ll)return;
    if (ll <= l && r <= rr) {
        if (ll == l) w = f[s];
        else
            combine(w, w, f[s], l - 1);
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) / 2 + 1, r, s + s + 1, ll, rr);
    combine(f[s], f[s+s],f[s+s+1], (l+ r) / 2);
}
int main() {
    scanf("%d", &n);
    ll ni100 = calc(100, mod - 2);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &x[i], &v[i], &p[i]);
        p[i] = mul(p[i], ni100);
    }
    for (int i = 1; i < n; i ++) {
        d.push_back(make_pair(i, make_pair(1,0) ) );
        if (v[i] > v[i + 1])
            d.push_back(make_pair(i, make_pair(1,1) ) );
        if (v[i] < v[i + 1])
            d.push_back(make_pair(i, make_pair(0,0) ) );
    }
    build(1, n ,1);
    sort(d.begin(), d.end(), [](pair<int, pair<int, int> > a, pair<int, pair<int, int> >  b) {
        return gett_double(a) < gett_double(b);
    });
    int ans = 0;
    for (auto u:d){
        get(1, n, 1, 1, u.first);
        node w1 = w;
        get(1, n, 1, u.first + 1, n);
        int v = gett_int(u);
        for (int i = 0; i < 2; i ++)
            for (int j = 0; j < 2; j ++)
                ans = add(ans, mul(mul(w1.v[i][u.second.first], w.v[u.second.second][j]), v));
        forbid[u.first][u.second.first][u.second.second] = 1;
        get(1, n, 1, u.first, u.first);
    }
    printf("%d\n", ans); 
    return 0;
}