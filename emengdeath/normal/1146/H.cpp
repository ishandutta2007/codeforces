#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
using namespace std;
const int N = 301;
long long f[N][N][5];
int n;
struct point{
    int x, y;
    point(int X = 0, int Y = 0)
    {
        x = X, y = Y;
    }
    int id()
    {
        if (x >= 0)
        {
            if (y >= 0) return 0;
            else
                return 3;
        } else
            if (y >= 0) return 1;
            else
                return 2;
    }
    long long operator*(point a)
    {
        return (long long)this->x * a.y - (long long)this->y * a.x;
    }
    bool operator<(point a)
    {
        if (this->id() != a.id())
            return this->id() < a.id();
        else
            return *this * a >= 0;
    }
    point operator-(point a)
    {
        return point(this->x - a.x, this->y - a.y);
    }
}a[N];
vector<pair<int, int> > d;
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return (a[x.second] - a[x.first]) < (a[y.second] - a[y.first]);
}
int main(){
    scanf("%d", &n);
    for (int i = 1;  i <= n ; i ++) {
        scanf("%d %d", &a[i].x, &a[i].y);
        f[i][i][0] = 1;
    }
    for (int i = 1 ; i <= n ; i ++)
        for (int j = 1; j <= n ;  j++)
            if (i != j)
                d.push_back(make_pair(i, j));
    sort(d.begin(), d.end(), cmp);
    for (auto u:d)
        for (int i = 0; i < 4; i ++)
            for (int j = 1; j <= n ; j ++)
                if (f[j][u.first][i] && j != u.second && (a[u.second] - a[u.first]) < (a[j] - a[u.second]))
                {
                    f[j][u.second][ i + 1] += f[j][u.first][i];
                }
    long long ans = 0;
    for (int i = 1; i <=  n ; i ++)
        for (int j = 1; j <= n ; j ++)
            ans += f[i][j][4];
    cout << ans;
    return 0;
}