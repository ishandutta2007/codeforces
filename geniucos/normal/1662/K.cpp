#include<bits/stdc++.h>

using namespace std;

double INF = 1e10;
typedef pair<double, double> point;
point A, B, C;

double ternarySearch(function<double(double)> f) {
    double l = -1e4, r = 1e4, best = INF;
    int steps = 43;
    while (steps --) {
        double mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;
        double c1 = f(mid1), c2 = f(mid2);
        if (c1 < best)
            best = c1;
        if (c2 < best)
            best = c2;
        if (c1 < c2)
            r = mid2;
        else
            l = mid1;
    }
    return best;
}

double doubleTernarySearch(function<double(double, double)> f) {
    //function<function<double(double)>(double)> h = [&](double x) {
    //};

    double l = -1e4, r = 1e4, best = INF;
    int steps = 43;
    while (steps --) {
        double mid1 = (2 * l + r) / 3, mid2 = (l + 2 * r) / 3;
         function<double(double)> h1 = [&](double y) {
            return f(mid1, y);
        };
         function<double(double)> h2 = [&](double y) {
            return f(mid2, y);
        };
        double c1 = ternarySearch(h1), c2 = ternarySearch(h2);
        if (c1 < best)
            best = c1;
        if (c2 < best)
            best = c2;
        if (c1 < c2)
            r = mid2;
        else
            l = mid1;
    }
    return best;
/*    function<double(double)> g = [&](double x) {
        function<double(double)> h = [&](double y) {
            return f(x, y);
        };
        return ternarySearch(h);
    };
    return ternarySearch(g);*/
}

void read(point &x) {
    int a, b;
    scanf ("%d %d", &a, &b);
    x.first = a, x.second = b;
}

double dist(point a, point b) {
    return (double) sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double sum3(point x) {
    return dist(x, A) + dist(x, B) + dist(x, C);
}

double minSum3(point a, point b, point c) {
    function<double(double, double)> f = [&](double x, double y) {
        point curr = {x, y};
        return dist(curr, a) + dist(curr, b) + dist(curr, c);
    };
    return doubleTernarySearch(f);
}

double cost(double x, double y) {
    point curr = {x, y};
    return max(minSum3(A, B, curr), max(minSum3(A, C, curr), minSum3(B, C, curr)));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read(A), read(B), read(C);
double ans = doubleTernarySearch(cost);
cout<<setprecision(15) << ans << '\n';
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/