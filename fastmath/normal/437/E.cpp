#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

#define ld long double
const ld PI = 4 * atan(1.);
const ld eps = 1e-10;
bool eq(ld x, ld y) {
    return abs(x - y) < eps;
}
bool ls(ld x, ld y) {
    return x < y && !eq(x, y);
}
bool lseq(ld x, ld y) {
    return x < y || eq(x, y);
}

int sgn(ld x) {
    if (eq(x, 0)) return 0;
    if (x > 0)
        return 1;
    else
        return -1;
}
ld sqr(ld x) {
    return x * x;
}
ld readLD() {
    double x;
    scanf("%lf", &x);
    return x;
}

struct Point {
    ld x, y;

    Point() : x(), y() {}
    Point (ld _x, ld _y) : x(_x), y(_y) {}

    void scan() {
        x = readLD();
        y = readLD();
    }
    void print() {
        printf("%.13lf %.13lf\n", (double)x, (double)y);
    }

    Point operator + (const Point &a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }
    Point operator * (const ld &k) const {
        return Point(x * k, y * k);
    }
    Point operator / (const ld &k) const {
        return Point(x / k, y / k);
    }
    ld operator % (const Point &a) const {
        return x * a.x + y * a.y;
    }
    ld operator * (const Point &a) const {
        return x * a.y - y * a.x;
    }
    ld sqrLen() const {
        return *this % *this;
    }
    ld len() const {
        return sqrtl(sqrLen());
    }
    Point norm() const {
        return *this / len();
    }
    Point ort() const {
        return Point(-y, x);
    }
    Point rot(const ld &ca, const ld &sa) const {
        return *this * ca + ort() * sa;
    }
    Point rot(const ld &ang) const {
        return rot(cosl(ang), sinl(ang));
    }

    bool operator == (const Point &a) const {
        return eq(x, a.x) && eq(y, a.y);
    }
    bool operator < (const Point &a) const {
        if (!eq(x, a.x)) return x < a.x;
        return ls(y, a.y);
    }
};

ld getAngle(Point v, Point u) {
    return atan2l(v * u, v % u);
}

bool onLine(Point A, Point B, Point C) {
    return eq((A - B) * (A - C), 0);
}
bool onSegm(Point A, Point B, Point C) {
    //if (!onLine(A, B, C)) return false;
    return lseq((A - B) % (C - B), 0);
}

bool intersectLines(Point A, Point a, Point B, Point b, Point &I) {
    if (eq(a * b, 0)) return false;
    ld y = ((A - B) * a) / (b * a);
    I = B + b * y;
    return true;
}

Point getH(Point P, Point A, Point a) {
    return A + a * (((P - A) % a) / a.sqrLen());
}

bool intersectLineCircle(Point A, Point a, Point O, ld R, Point &I1, Point &I2) {
    Point H = getH(O, A, a);
    ld h = (O - H).len();
    if (ls(R, h)) return false;
    if (eq(R, h)) {
        I1 = I2 = H;
        return true;
    }
    ld x = sqrtl(sqr(R) - sqr(h));
    a = a.norm();
    I1 = H + a * x;
    I2 = H - a * x;
    return true;
}

bool intersectCircles(Point O1, ld R1, Point O2, ld R2, Point &I1, Point &I2) {
    if (R1 < R2) {
        swap(R1, R2);
        swap(O1, O2);
    }
    ld L = (O1 - O2).len();
    if (ls(R1 + R2, L) || ls(L, R1 - R2) || eq(L, 0)) return false;
    if (eq(R1 + R2, L) || eq(L, R1 - R2)) {
        I1 = I2 = O1 + (O2 - O1).norm() * R1;
        return true;
    }
    ld x = (sqr(L) + sqr(R1) - sqr(R2)) / (2 * L);
    Point a = (O2 - O1).norm();
    Point H = O1 + a * x;
    a = a.ort() * sqrtl(sqr(R1) - sqr(x));
    I1 = H + a;
    I2 = H - a;
    return true;
}

bool insidePolygon(Point P, const vector<Point> &a) {
    // it is usually convinient to copy the first vertex of a polygon to its end
    for (int i = 0; i < (int)a.size() - 1; i++) {
        if (onLine(a[i], P, a[i + 1]) && onSegm(a[i], P, a[i + 1])) { // because onSegm doesn't check onLine by default
            return true; // depends on whether you want strictly inside or not
        }
    }
    ld ang = 0;
    for (int i = 0; i < (int)a.size() - 1; i++)
        ang += getAngle(a[i] - P, a[i + 1] - P);
    return abs(ang) > 1;
}

ld polygonArea(const vector<Point> &a) {
    ld S = 0;
    for (int i = 0; i < (int)a.size() - 1; i++)
        S += a[i] * a[i + 1];
    return abs(S) / 2;
}

/*
int getQ(const Point &v) {
    if (v.y > 0 || (v.y == 0 && v.x > 0)) return 0;
    return 1;
}
bool cmp(const Point &v, const Point &u) {
    int q1 = getQ(v), q2 = getQ(u);
    if (q1 != q2) return q1 < q2;
    if (v * u != 0) return v * u > 0;
    return v.sqrLen() < u.sqrLen();
}
*/

bool cmp(const Point &v, const Point &u) {
    ld x = v * u;
    if (!eq(x, 0)) return x > 0;
    return ls(v.sqrLen(), u.sqrLen());
}
vector<Point> graham(vector<Point> a) {
    Point minP = a[0];
    for (int i = 0; i < (int)a.size(); i++) {
        minP = min(minP, a[i]);
    }
    for (int i = 0; i < (int)a.size(); i++)
        a[i] = a[i] - minP;
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < (int)a.size(); i++)
        a[i] = a[i] + minP;
    int m = 0;
    for (Point P : a) {
        while(m > 2 && lseq(0, (P - a[m - 1]) * (P - a[m - 2]))) {
            m--;
        }
        a[m++] = P;
    }
    a.resize(m);
    return a;
}

bool tangentsFromPoint(Point P, Point O, ld R, Point &I1, Point &I2) {
    ld L = (P - O).len();
    if (lseq(L, R)) return false;
    ld ang = acosl(R / L);
    Point a = (P - O).norm() * R;
    I1 = O + a.rot(ang);
    I2 = O + a.rot(-ang);
    return true;
}

ld distPointSegment(Point A, Point P, Point Q) {
    Point H = getH(A, P, Q - P);
    if (onSegm(P, H, Q))
        return (A - H).len();
    else
        return min((A - P).len(), (A - Q).len());
}

bool onSameSide(Point P, Point Q, Point A, Point a) {
    return sgn(a * (P - A)) * sgn(a * (Q - A)) == 1;
}

bool intersectSegments(Point A, Point B, Point C, Point D) {
    if (eq(0, (A - B) * (C - D))) {
        if (!onLine(A, B, C)) return false;
        Point a = B - A;
        if (a == Point()) a = D - C;
        if (a == Point()) return A == C;
        ld l1 = A % a, r1 = B % a, l2 = C % a, r2 = D % a;
        if (l1 > r1) swap(l1, r1);
        if (l2 > r2) swap(l2, r2);
        return lseq(max(l1, l2), min(r1, r2));
    }
    return !onSameSide(A, B, C, D - C) && !onSameSide(C, D, A, B - A);
}

ld distSegments(Point A, Point B, Point C, Point D) {
    if (intersectSegments(A, B, C, D)) return 0;
    return min(min(distPointSegment(A, C, D), distPointSegment(B, C, D)),
               min(distPointSegment(C, A, B), distPointSegment(D, A, B)));
}

template<int MOD, int RT> struct mint {
    static const int mod = MOD;
    static constexpr mint rt() { return RT; } // primitive root for FFT
    int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
    mint() { v = 0; }
    mint(ll _v) { v = (int)((-MOD < _v && _v < MOD) ? _v : _v % MOD);
        if (v < 0) v += MOD; }
    friend bool operator==(const mint& a, const mint& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mint& a, const mint& b) { 
        return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { 
        return a.v < b.v; }
    friend string ts(mint a) { return to_string(a.v); }

    mint& operator+=(const mint& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mint& operator-=(const mint& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mint& operator*=(const mint& m) { 
        v = (int)((ll)v*m.v%MOD); return *this; }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }
    friend mint pow(mint a, ll p) {
        mint ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    mint & operator ^=(const int &p) { return (*this) = pow(this, p); }

    friend mint inv(const mint& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }
        
    mint operator-() const { return mint(-v); }
    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend mint operator^(mint a, const int p) { return pow(a, p); }
};

const int MOD = 1e9+7;

typedef mint<MOD,5> mi; // 5 is primitive root for both common mods
typedef vector<mi> vmi;

std::ostream& operator << (std::ostream& o, const mi& a)
{
    cout << a.v;
    return o;
}

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
    scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
    FORI(i,1,SZ) FOR(j,i+1) 
        scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}
 
vmi invs, fac, ifac; // make sure to convert to LL before doing any multiplications ...
void genFac(int SZ) {
    invs.resize(SZ), fac.resize(SZ), ifac.resize(SZ); 
    invs[1] = fac[0] = ifac[0] = 1; 
    FORI(i,2,SZ) invs[i] = mi(-(ll)MOD/i*(int)invs[MOD%i]);
    FORI(i,1,SZ) {
        fac[i] = fac[i-1]*i;
        ifac[i] = ifac[i-1]*invs[i];
    }
}
mi comb(int a, int b) {
    if (a < b || b < 0) return 0;
    assert(a < fac.size());
    return fac[a]*ifac[b]*ifac[a-b];
}
const int N = 207;
mi dp[N][N];
signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    V <Point> a(n);
    FOR (i, n) {
        cin >> a[i].x >> a[i].y;
    }

    ld S = 0;
    for (int i = 1; i + 1 < n; ++i) {
        S += (a[i] - a[0]) * (a[i + 1] - a[0]);
    }

    if (S < 0) {
        reverse(all(a));
    }

    FOR (i, n) {
        dp[i][i] = dp[i][i + 1] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = i + 1; k < j; ++k) {
                if ((a[k] - a[i]) * (a[j] - a[i]) > 0) {
                    dp[i][j] += dp[i][k] * dp[k][j];
                }
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}