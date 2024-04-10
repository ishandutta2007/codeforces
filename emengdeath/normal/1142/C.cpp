#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 3e5+ 1;
vector<int>heap[N];
struct point{
    long long x, y;
    point(long long X = 0, long long Y = 0)
    {
        x = X, y = Y;
    }
    long long operator*(point b)
    {
        return this->x * b.y - this->y * b.x;
    }
    point operator-(point b)
    {
        return point(this->x - b.x, this->y - b.y);
    }
}a[N], d[N];
int n, r;
long long cross(point a, point b, point c)
{
    return (b - a) * (c - a);
}
bool cmp(const point & a, const point & b)
{
    return a.x < b.x || (a.x == b.x && a.y > b.y);
}
long long calc(long long x)
{
    return x * (x - 1) / 2;
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
    {
        scanf("%lld %lld", &a[i].x, &a[i].y);
        a[i].y -= a[i].x * a[i].x;
    }
    sort(a + 1, a + n + 1, cmp);
    r = 1;
    d[1] = a[1];
    for (int i = 2; i <= n ; i ++)
        if (a[i].x == a[i - 1].x) continue;
        else{
            while (r > 1 && cross(d[r - 1], d[r], a[i]) >= 0) r--;
            d[++ r] = a[i];
        }
    printf("%d\n", r - 1);
    return 0;
}