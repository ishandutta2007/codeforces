#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define double long double
 
const int N = 201, C = 107, LG = 15;
 
void clear(double a[N][N], bool t) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = t * (i == j);
}   
void cop(double a[N][N], double b[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = b[i][j];
}   
double t[N][N];
void add(double a[N][N], double b[N][N]) {
    clear(t, 0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                t[i][j] += a[i][k] * b[k][j];
    cop(a, t);
}   
double tt[N];
double add(double a[N], double b[N][N]) {
    for (int i = 0; i < N; ++i)
        tt[i] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            tt[i] += b[i][j] * a[j];
    for (int i = 0; i < N; ++i)
        a[i] = tt[i];                      
}    
 
struct Line {
    int a, b, c;
    bool check(ii p) {
        return a * p.f + b * p.s + c == 0;
    }   
    Line (ii x, ii y) {
        a = x.s - y.s;
        b = y.f - x.f;
        c = x.f * y.s - x.s * y.f;
 
        int d = __gcd(a, __gcd(b, c));
        a /= d;
        b /= d;
        c /= d;
 
        if (a < 0) {
            a = -a;
            b = -b;
            c = -c;
        }   
    }   
    Line () {}
    bool operator < (const Line l) const {
        return (a < l.a) || (a == l.a && b < l.b) || (a == l.a && b == l.b && c < l.c);
    }   
    bool operator == (const Line l) const {
        return a == l.a && b == l.b && c == l.c;
    }   
};   
int n, q;
ii a[N];    
int cnt[N]; 
vector <vector <int> > who;
double p[LG][N][N], to[N], g[N][N];
void calc_to(int m, int want) {
    for (int i = 0; i < N; ++i)
        to[i] = 0;
    to[want] = 1;
    for (int i = 0; i < LG; ++i) {
        if ((m >> i) & 1) {
            add(to, p[i]);
        }   
    }                   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].f >> a[i].s;

    vector <Line> lv;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            lv.app(Line(a[i], a[j]));
    
    sort(all(lv));
    lv.resize(unique(all(lv)) - lv.begin());
 
    int num = 0;
    for (auto l : lv) {
        who.app({});
        for (int i = 0; i < n; ++i)
            if (l.check(a[i])) {
                who.back().app(i);
                ++cnt[i];
            }        
        double t = 1.0/who.back().size();
        for (int i : who.back())
            for (int j : who.back())
                g[i][j] += t;
        ++num;
    }    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] /= cnt[i];
    cop(p[0], g);
    for (int i = 1; i < LG; ++i) {
        cop(p[i], p[i - 1]);
        add(p[i], p[i - 1]);
    }   

    cin >> q;
    while (q--) {
        int want, m;
        cin >> want >> m;
        --want;
        
        calc_to(m, want);
        double ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, to[i]);

        calc_to(m-1, want);
        for (int lnum = 0; lnum < lv.size(); ++lnum) {
            Line l = lv[lnum];
            double sum = 0;
            for (int i : who[lnum]) {
                sum += to[i];       
            }   
            ans = max(ans, sum / who[lnum].size());
        }   
        
        cout << ans << endl;
    }
}