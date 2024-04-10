#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
 
using namespace std;
typedef long double ld;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
            abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

const int MAXN = 5000;

int N, K;
P pt[MAXN];

pair <P, double> res[4];

ld cdist (pair <P, double> left, pair <P, double> right)
{
    return abs(left.first.x - right.first.x) + abs (left.first.y - right.first.y) + abs(left.second - right.second);
}

void gogo()
{
    while (true)
    {
        int cval = 0;
        while (cval < K)
        {
            int a = rand() % (N * K), b = rand() % (N * K), c = rand() % (N * K);
            if (a == b || a == c || b == c) continue;
            if (!((pt[b]-pt[a]).cross(pt[c]-pt[a]))) continue;
            P cc = ccCenter(pt[a], pt[b], pt[c]);
            double rad = ccRadius(pt[a], pt[b], pt[c]);
            if (cc.dist() > 1050000 || rad < 200000 || rad > 800000) continue;

            bool bad = false;
            for (int i = 0; i < cval; i++)
            {
                if (cdist (res[i], make_pair (cc, rad)) < 350000)
                {
                    bad = true;
                    break;
                }
            }
            if (bad) continue;

            int nhit = 0;
            vector <double> v;
            for (int i = 0; i < N * K; i++)
            {
                double d = (cc-pt[i]).dist();
                if (d > 0.87 * rad && d < 1.13 * rad)
                {
                    nhit++;
                    v.push_back((cc-pt[i]).angle());
                }
            }
            sort(v.begin(), v.end());
            for (int i = 0; i + 1 < v.size(); i++)
                if (v[i+1] - v[i] > 1)
                {
                    //if (nhit >= N)
                    //    cout << v[i+1] - v[i] << "\n";
                    bad = true;
                }
            if (bad) continue;

            if (nhit >= N)
            {
                res[cval] = make_pair (cc, rad);
                cval++;
            }
        }

        bool bad = false;
        for (int i = 0; i < N * K; i++)
        {
            bool found = false;
            for (int j = 0; j < K; j++)
            {
                double d1 = res[j].second, d2 = (res[j].first-pt[i]).dist();
                if (d2 >= 0.8 * d1 && d2 <= 1.2 * d1)
                    found = true;
            }
            if (!found)
            {
                bad = true;
                break;
            }
        }
        if (!bad) break;
    }
}

int main()
{
    srand(time(NULL));
    cin >> K >> N;
    for (int i = 0; i < N * K; i++)
    {
        cin >> pt[i].x >> pt[i].y;
    }

    gogo();

    cout << fixed << setprecision(8);
    for (int i = 0; i < K; i++)
    {
        cout << res[i].first.x << " " << res[i].first.y << " " << res[i].second << "\n";
    }
}