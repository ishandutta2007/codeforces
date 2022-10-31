#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define N 100020
#define EPS 1e-12
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

    Point operator+(const Point that)
    {
        return Point(this -> x + that.x, this -> y + that.y);
    }

    Point operator-(const Point that)
    {
        return Point(this -> x - that.x, this -> y - that.y);
    }

    Point operator*(double that)
    {
        return Point(this -> x * that, this -> y * that);
    }

    bool operator<(Point that)
    {
        return this -> x == that.x ? this -> y < that.y : this -> x < that.x;
    }

    bool operator==(Point that)
    {
        return this -> x == that.x && this -> y == that.y;
    }

    double Dot(Point that)
    {
        return this -> x * that.x + this -> y * that.y;
    }

    double Cross(Point that)
    {
        return this -> x * that.y - this -> y * that.x;
    }
};

Point a[N];
Point f[N];

Point Intersect(Point a, Point x, Point b, Point y)
{
    return a + x * (y.Cross(a - b) / x.Cross(y));
}

int main(void)
{
    int n, p, q;
    int i, c;
    double x, y;
    Point t;

    scanf("%d %d %d", &n, &p, &q);
    for(i = x = y = 0; i < n; i ++)
    {
        scanf("%lf %lf", &a[i].x, &a[i].y);
        x = max(x, a[i].x);
        y = max(y, a[i].y);
    }
    sort(a, a + n);
    // for(i=0;i<n;i++)cout<<a[i].x<<' '<<a[i].y<<endl;

    c = 0;
    f[c ++] = Point(0, 0);
    f[c ++] = Point(0, y);
    for(i = 0; i < n; i ++)
    {
        while(c > 1 && (a[i] - f[c - 1]).Cross(f[c - 2] - f[c - 1]) >= -EPS)
            c --;
        f[c ++] = a[i];
    }
    f[c ++] = Point(x, 0);

    // for(i=0;i<c;i++)printf("%f %f\n",f[i].x,f[i].y);

    for(i = 2; i < c; i ++)
    {
        // printf("%f %f %f\n",(f[i] - f[i - 1]).x,(f[i] - f[i - 1]).y,(f[i] - f[i - 1]).Cross(Point(1, 1)));
        if(fabs((f[i] - f[i - 1]).Cross(Point(p, q))) > EPS)
        {
            t = Intersect(f[i], f[i] - f[i - 1], Point(0, 0), Point(p, q));
            // printf("vertex %f %f %f %f\n",t.x,t.y,t.Dot(f[i]),t.Dot(f[i-1]));
            if((f[i] - t).Dot(f[i] - f[i - 1]) * (f[i - 1] - t).Dot(f[i] - f[i - 1]) < EPS)
            {
                printf("%.10f\n", p / t.x);
                break;
            }
        }
    }

    return 0;
}