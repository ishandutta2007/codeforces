#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 100000
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

    Point Normal(void)
    {
        return Point(-y, x);
    }

    bool operator<(Point that) const
    {
        return this -> x != that.x ? this -> x < that.x : this -> y < that.y;
    }

    bool operator!=(Point that) const
    {
        return this -> x != that.x || this -> y != that.y;
    }
};

void Convex(vector<Point> &x)
{
    int i;
    vector<Point> f, g;

    sort(x.begin(), x.end());
    for(i = 0; i < (signed)x.size(); i ++)
    {
        for(; f.size() > 1 && (f.back() - f[f.size() - 2]).Cross(x[i] - f.back()) <= 0; f.pop_back())
            ;
        f.push_back(x[i]);
    }
    for(i = (signed)x.size() - 1; i > -1; i --)
    {
        for(; g.size() > 1 && (g.back() - g[g.size() - 2]).Cross(x[i] - g.back()) <= 0; g.pop_back())
            ;
        g.push_back(x[i]);
    }

    x = f;
    for(i = 0; i < (signed)g.size(); i ++)
        if(g[i] != f.front() && g[i] != f.back())
            x.push_back(g[i]);

    return;
}

Point Intersect(Point x, Point a, Point y, Point b)
{
    return x + a * (b.Cross(x - y) / a.Cross(b));
}

double Circle(Point x, Point y, Point z)
{
    Point o;

    o = Intersect((x + y) * 0.5, (y - x).Normal(), (x + z) * 0.5, (z - x).Normal());

    return (o - x).Dot(o - x);
}

int main(void)
{
    int n, x, y, v;
    vector<Point> f;
    int i;
    double t;
    pair<double, int> o;

    scanf("%d", &n);
    while(n --)
    {
        scanf("%d %d %d", &x, &y, &v);
        if(x - v >= 0)
            f.push_back(Point(x - v, y));
        else
        {
            f.push_back(Point(0, max(0, y - (v - x))));
            f.push_back(Point(0, min(N, y + (v - x))));
        }
        if(x + v <= N)
            f.push_back(Point(x + v, y));
        else
        {
            f.push_back(Point(N, max(0, y - (x + v - N))));
            f.push_back(Point(N, min(N, y + (x + v - N))));
        }
        if(y - v >= 0)
            f.push_back(Point(x, y - v));
        else
        {
            f.push_back(Point(max(0, x - (v - y)), 0));
            f.push_back(Point(min(N, x + (v - y)), 0));
        }
        if(y + v <= N)
            f.push_back(Point(x, y + v));
        else
        {
            f.push_back(Point(max(0, x - (y + v - N)), N));
            f.push_back(Point(min(N, x + (y + v - N)), N));
        }
    }

    Convex(f);
    for(i = 0, o = make_pair(-1, -1); i < (signed)f.size(); i ++)
    {
        t = Circle(f[i], f[(i + 1) % f.size()], f[(i + 2) % f.size()]);
        if(t > o.first)
            o = make_pair(t, i);
    }
    printf("%.0f %.0f\n%.0f %.0f\n%.0f %.0f\n", f[o.second].x, f[o.second].y, f[(o.second + 1) % f.size()].x, f[(o.second + 1) % f.size()].y, f[(o.second + 2) % f.size()].x, f[(o.second + 2) % f.size()].y);

    return 0;
}