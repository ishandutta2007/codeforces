#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <tuple>
#define N 200020
#define M 18
#define EPS 1e-10
using namespace std;

class Point
{
public:
    double x;
    double y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y)
    {
        return;
    }

    Point operator+(Point that)
    {
        return Point(this -> x + that.x, this -> y + that.y);
    }

    Point operator-(Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    Point operator*(double that)
    {
        return Point(this -> x * that, this -> y * that);
    }

    double Dot(Point that)
    {
        return this -> x * that.x + this -> y * that.y;
    }

    double Cross(Point that)
    {
        return this -> x * that.y - this -> y * that.x;
    }

    double Length(void)
    {
        return sqrt(Dot(*this));
    }

    Point Rotate(double r)
    {
        return Point(this -> Cross(Point(sin(r), cos(r))), this -> Dot(Point(sin(r), cos(r))));
    }

    Point Reduce(void)
    {
        return *this * (1 / Length());
    }

    Point Normal(void)
    {
        return Point(-y, x) * (1 / Length());
    }
};

class Circle
{
public:
    Point o;
    double r;

    Circle(Point _o, double _r = 0) : o(_o), r(_r)
    {
        return;
    }
};

Point a[N];
pair<double, double> b[N];
tuple<int, int, int> c[N];
int f[M][N], g[N], q[M][N];
vector<pair<int, int> > h;
int s[N];

inline int Lowbit(int x)
{
    return x & -x;
}

void AddFenwick(int p, int n)
{
    for(; p <= n; p += Lowbit(p))
        s[p] ++;

    return;
}

int SumFenwick(int p)
{
    int o;

    for(o = 0; p; p -= Lowbit(p))
        o += s[p];

    return o;
}

bool Compare(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<1>(a) < get<1>(b);
}

pair<Point, Point> CircleIntersect(Circle x, Circle y)
{
    double l, p, d;

    // printf("intersect : %f %f\n", x.r, y.r);

    l = (y.o - x.o).Length();
    p = (x.r * x.r - y.r * y.r + l * l) / l / 2;
    // if(x.r*x.r-p*p<0){printf("??? %f %f\n",x.r,p);}
    d = sqrt(fabs(x.r * x.r - p * p));
    // printf("may len %f\n", d);

    return make_pair(x.o + (y.o - x.o).Reduce() * p + (y.o - x.o).Normal() * d, x.o + (y.o - x.o).Reduce() * p - (y.o - x.o).Normal() * d);
}

pair<double, double> Tangent(Point x, Circle y)
{
    Point t;
    pair<Point, Point> o;

    if(fabs((x - y.o).Length() - y.r) < EPS)
        return make_pair(atan2(x.y, x.x), atan2(x.y, x.x));
    // printf("length %f\n", (x - y.o).Length());

    t = x + (y.o - x) * 0.5;
    o = CircleIntersect(Circle(t, (y.o - x).Length() / 2), y);

    // printf("[%f,%f] [%f,%f] ",o.first.x,o.first.y,o.second.x,o.second.y);

    return make_pair(atan2(o.first.y, o.first.x), atan2(o.second.y, o.second.x));
}

int MaxRMQ(int l, int r)
{
    int t;

    t = 31 - __builtin_clz(r - l + 1);

    return max(q[t][l], q[t][r - (1 << t) + 1]);
}

int BSFind(int x, int n)
{
    int l, m, r;

    for(l = x, r = n; l + 1 < r; )
    {
        m = (l + r) >> 1;
        if(MaxRMQ(x + 1, m) > get<1>(c[x]))
            r = m;
        else
            l = m;
    }

    return r;
}

int CountColor(int n, int m)
{
    static int v[N], t[N];
    static vector<pair<int, int> > e[2][N];
    int i, j, p, o;

    fill(t, t + m, n);
    fill(s, s + N, 0);
    for(i = 0; i < n; i ++)
    {
        e[0][i].clear();
        e[1][i].clear();
    }
    for(i = 0; i < (signed)h.size(); i ++)
    {
        if(h[i].first)
            e[0][h[i].first - 1].push_back(make_pair(h[i].second, i));
        e[1][h[i].second].push_back(make_pair(h[i].second, i));
    }

    for(i = n - 1; i > -1; i --)
    {
        p = t[g[i]];
        t[g[i]] = i;
        g[i] = p;
    }
    for(i = o = 0; i < n; i ++)
    {
        AddFenwick(g[i], n);
        for(j = 0; j < (signed)e[0][i].size(); j ++)
            v[e[0][i][j].second] = SumFenwick(n) - SumFenwick(e[0][i][j].first);
        for(j = 0; j < (signed)e[1][i].size(); j ++)
            o = max(o, SumFenwick(n) - SumFenwick(e[1][i][j].first) - v[e[1][i][j].second]);
    }

    return o;
}

bool Solve(int n, int m, double l)
{
    int s;
    int i, j, p;
    vector<double> t, v;

    for(i = 0; i < n; i ++)
    {
        if(a[i].Length() < l)
            return false;
        b[i] = Tangent(a[i], Circle(Point(0, 0), l));
        t.push_back(b[i].first );
        t.push_back(b[i].second);
        // printf("tangent %d : %f-%f\n", i, b[i].first, b[i].second);
        // cout<<b[i].first<<' '<<b[i].second<<' ';
        // if(isnan(b[i].first)||isnan(b[i].second))throw;
    }//cout<<endl;

    // v.push_back(acos(-1));
    // puts("pushed");
    sort(t.begin(), t.end());
    for(i = 0; i < (signed)t.size(); i ++)
        if(v.empty() || fabs(t[i] - v.back()) > EPS)
            v.push_back(t[i]);
    s = (int)v.size();
    // printf("added %d\n",s);
    // for(i=0;i<(int)t.size();i++)cout<<t[i]<<' ';cout<<endl;
    // for(i=0;i<s;i++)cout<<v[i]<<' ';cout<<endl;
    // for(i=1;i<s;i++)if(v[i]<v[i-1])throw;
    for(i = 0; i < n; i ++)
    {
        get<0>(c[i]) = (int)(lower_bound(v.begin(), v.end(), b[i].first ) - v.begin());
        get<1>(c[i]) = (int)(lower_bound(v.begin(), v.end(), b[i].second) - v.begin());
        if(get<1>(c[i]) < get<0>(c[i]))
            get<1>(c[i]) += s;

        get<0>(c[i + n]) = get<0>(c[i]) + s;
        get<1>(c[i + n]) = get<1>(c[i]) + s;
        // printf("%d : %d-%d\n", i, get<0>(c[i]), get<1>(c[i]));
    }
    for(i = 0; i < n * 2; i ++)
        get<2>(c[i]) = i;

    sort(c, c + n * 2, Compare);
    for(i = 0; i < n * 2; i ++)
    {
        q[0][i] = get<0>(c[i]);
        g[i] = get<2>(c[i]);
        if(g[i] >= n)
            g[i] -= n;
    }
    for(i = 1; i < M; i ++)
        for(j = 0; j + (1 << i) - 1 < n * 2; j ++)
            q[i][j] = max(q[i - 1][j], q[i - 1][j + (1 << (i - 1))]);

    for(i = 0; i < n * 2; i ++)
        f[0][i] = BSFind(i, n * 2);
    for(i = 0; i < M; i ++)
        f[i][n * 2] = n * 2;
    for(i = 1; i < M; i ++)
        for(j = 0; j < n * 2; j ++)
            f[i][j] = f[i - 1][f[i - 1][j]];

    h.clear();
    for(i = 0; i < n * 2; i ++)
    {
        for(j = 0, p = i; j < M; j ++)
            if(m & (1 << j))
                p = f[j][p];
        h.push_back(make_pair(i, p - 1));
        // if(CountColor(i, p - 1) >= n)
        //     return true;
    }

    return CountColor(n * 2, n) >= n;
}

int main(void)
{
    int n, m;
    int i;
    double l, r, v;

    scanf("%d %d", &n, &m);
    v = acos(-1) * 2 * rand() / RAND_MAX;
    for(i = 0; i < n; i ++)
    {
        scanf("%lf %lf", &a[i].x, &a[i].y);
        a[i] = a[i].Rotate(v);
    }

    // if(n == 100000 && m == 1 && a[0].x == -3 && a[0].y == 90007)
    // {
    //     printf("0\n");

    //     return 0;
    // }

    // cout << Solve(n, m, 0.496138) << endl;
    // return 0;

    for(l = 0, r = 1e9; r - l > EPS; )
        if(Solve(n, m, (l + r) / 2))
            l = (l + r) / 2;
        else
            r = (l + r) / 2;
    printf("%.10f\n", l);

    return 0;
}