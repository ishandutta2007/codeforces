#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 1e6+7;
struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    if (r < l)
        return 0;
    return get(r) - get(l - 1);
}   
} f;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, l, t;
    cin >> n >> l >> t;
    t <<= 1;

    int d = t/l;
    t %= l;

    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    double ans = (n * (n - 1) / 2.) * d/2.;
    for (int i = 0; i < n; ++i) {
        ans += f.get(lower_bound(all(a), a[i]-t)-a.begin(), i)/4.;
        f.add(i, 1);
    }   

    //debug(ans);
    f.clear();

    vector <int> c;
    for (auto e : a)
        c.app(l - e);
    sort(all(c));

    for (int i = n - 1; i >= 0; --i) {
        ans += f.get(upper_bound(all(c), t - a[i]) - c.begin()-1)/4.;
        f.add(lower_bound(all(c), l - a[i]) - c.begin(), 1);
    }   
    cout.precision(20);
    cout << ans << endl;
}