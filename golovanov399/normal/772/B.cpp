#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct point
{
    ld x, y;
    
    point(ld x = 0, ld y = 0): x(x), y(y) {}
    
    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    
    ld vprod(const point& p) const { return x * p.y - y * p.x; }
    
    point operator/(ld t) const { return point(x / t, y / t); }
    
    ld length() const { return sqrt(x * x + y * y); }
};

ld answer = 1e18;

void consider(point a, point b, point c)
{
    for (int t = 0; t < 3; t++)
    {
        point vec = (b - c);
        vec = vec / vec.length();
        
        answer = min(answer, abs((a - c).vprod(vec)));
        
        // a b c - > b a c -> b c a
        swap(a, b);
        swap(b, c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<point> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    
    for (int i = 0; i < n; i++)
        consider(p[i], p[(i + 1) % n], p[(i + 2) % n]);
    
    cout << fixed << setprecision(12) << (answer / 2) << endl;
    
    return 0;
}