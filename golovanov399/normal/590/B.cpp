#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

pair<double, double> tms(pair<double, double> u, pair<double, double> v, double vmax){
    double a = vmax * vmax - v.x * v.x - v.y * v.y;
    double b = -2 * (u.x * v.x + u.y * v.y);
    double c = -(u.x * u.x + u.y * u.y);
    assert(b * b - 4 * a * c + 1e-13 >= 0);
    double D = sqrt(b * b - 4 * a * c + 1e-13);
    return {(-b - D) / 2 / a, (-b + D) / 2 / a};
}

int main(){

    pair<double, double> p, q;
    cin >> p.x >> p.y >> q.x >> q.y;
    int vmax, t;
    cin >> vmax >> t;
    pair<double, double> v, w;
    cin >> v.x >> v.y >> w.x >> w.y;
    v.x *= -1;
    v.y *= -1;
    w.x *= -1;
    w.y *= -1;
    pair<double, double> u = {q.x - p.x, q.y - p.y};
    auto res = tms(u, v, vmax);
    cout << setprecision(10) << fixed;
    if (res.x > 0 && res.x < t){
        cout << res.x << "\n";
        return 0;
    }
    if (res.y > 0 && res.y < t){
        cout << res.y << "\n";
        return 0;
    }
    u = {q.x - p.x + (v.x - w.x) * t, q.y - p.y + (v.y - w.y) * t};
    res = tms(u, w, vmax);
    if (res.x > 0){
        cout << res.x << "\n";
        return 0;
    }
    if (res.y > 0){
        cout << res.y << "\n";
        return 0;
    }

    return 0;
}