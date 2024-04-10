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

// long long gcd(long long x, long long y){
//  while (y){
//      x %= y;
//      swap(x, y);
//  }
//  return x;
// }

// struct rat{
//  long long a, b;

//  rat(long long x = 0, long long y = 1):a(x),b(y){}

//  rat operator *(const rat& r) const {
//      return rat(a * r.a, b * r.b);
//  }

//  rat operator /(const rat& r) const {
//      return rat(a * r.b, b * r.a);
//  }

//  rat operator +(const rat& r) const {
//      return rat(a * r.b + b * r.a, b * r.b);
//  }

//  rat operator -(const rat& r) const {
//      return rat(a * r.b - b * r.a, b * r.b);
//  }

//  void norm(){
//      long long g = gcd(abs(a), abs(b));
//      a /= g;
//      b /= g;
//      if (b < 0){
//          b *= -1;
//          a *= -1;
//      }
//  }

//  void out() const {
//      cerr << a << "/" << b << " ";
//  }
// };

const long double eps = 1e-14;

inline long double vec(const pair<long double, long double>& p, const pair<long double, long double>& q){
    return p.x * q.y - p.y * q.x;
}

void qwq(pair<long double, long double>& p){
    if (p.x < -eps || (p.x < eps && p.y < -eps)){
        p.x = -p.x;
        p.y = -p.y;
    }
}

bool cmp(pair<long double, long double> p, pair<long double, long double> q){
    qwq(p);
    qwq(q);
    return p.x * q.y - p.y * q.x < -eps;
}

int main(){

    int n = nxt();
    vector<pair<long double, long double>> a;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int x = nxt(), y = nxt(), z = nxt();
        if (z == 0)
            cnt++;
        else {
            long double X = 1.0 * x / z;
            long double Y = 1.0 * y / z;
            long double d = X * X + Y * Y;
            X /= d;
            Y /= d;
            a.push_back({X, Y});
        }
    }

    // for (int i = 0; i < n; i++)
    //  cerr << "(" << a[i].x << ", " << a[i].y << ")\n";

    long long ans = 0;
    n = a.size();
    if (cnt == 2)
        ans = n;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            a[j].x -= a[i].x;
            a[j].y -= a[i].y;
        }
        sort(a.begin() + i + 1, a.end(), &cmp);
        int cur = 1;
        for (int j = i + 2; j < n; j++){
            if (fabs(vec(a[j], a[j - 1])) < eps)
                cur += 1;
            else {
                ans += cur * (cur - 1) / 2;
                cur = 1;
            }
        }
        ans += cur * (cur - 1) / 2;
    }
    cout << ans << "\n";

    return 0;
}