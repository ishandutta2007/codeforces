    #ifndef Local
    #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
    #pragma GCC target( \
        "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
    #pragma comment(linker, "/STACK:1024000000,1024000000")
    #endif
     
    #include <bits/stdc++.h>
     
    #include <ext/numeric>
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
    using namespace __gnu_cxx;
    using namespace std;
     
    #define popCnt(x) (__builtin_popcountll(x))
    #define sz(x) ((int)(x.size()))
    #define all(v) begin(v), end(v)
     
    typedef long long Long;
    typedef long double Double;
    typedef vector<int> vi;
     
    const int N = 2e5 + 5;
     
    template <class T>
    int sgn(T x) {
      return (x > 0) - (x < 0);
    }
     
    template <class T>
    struct Point {
      typedef Point P;
      T x, y;
      explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
      bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
      bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
      P operator+(P p) const { return P(x + p.x, y + p.y); }
      P operator-(P p) const { return P(x - p.x, y - p.y); }
      P operator*(T d) const { return P(x * d, y * d); }
      P operator/(T d) const { return P(x / d, y / d); }
      T cross(P p) const { return x * p.y - y * p.x; }
      T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    };
     
    typedef Point<Double> P;
    const Double g = 9.8;
     
    Double getY(Double angle, P wall, int v) {
      Double t = wall.x / cos(angle) / v;
      Double y = v * sin(angle) * t - g * t * t / 2;
      return y;
    }
     
    Double getZero(Double angle, Double v) {
      Double t = v * sin(angle) * 2 / g;
      return v * cos(angle) * t;
    }
     
    struct Query {
      Double angle;
      int ind;
    } queries[N];
     
    P res[N];
     
    int main() {
      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef Local
      freopen("test.in", "r", stdin);
    #else
    #define endl '\n'
    #endif
     
      int n, v;
      cin >> n >> v;
     
      for (int i = 0; i < n; ++i) {
        cin >> queries[i].angle;
        queries[i].ind = i;
      }
     
      sort(queries, queries + n,
           [](const Query& a, const Query& b) { return a.angle < b.angle; });
     
      int m;
      cin >> m;
      vector<P> walls(m);
     
      for (int i = 0; i < m; ++i) {
        cin >> walls[i].x >> walls[i].y;
      }
     
      sort(walls.begin(), walls.end());
     
      int curr_wall = 0;
      cout << fixed << setprecision(10);
      for (int i = 0; i < n; ++i) {
        auto query = queries[i];
        Double x0 = getZero(query.angle, v);
        if (x0 <= walls[curr_wall].x) {
          res[query.ind] = P(x0, 0);
          continue;
        }
        Double y;
        while (curr_wall != m) {
          y = getY(query.angle, walls[curr_wall], v);
          if (y <= walls[curr_wall].y) break;
          ++curr_wall;
        }
        if (curr_wall == m) {
          res[query.ind] = P(x0, 0);
          continue;
        }
        res[query.ind] = P(walls[curr_wall].x, y);
      }
     
      for (int i = 0; i < n; ++i) {
        cout << res[i].x << " " << res[i].y << endl;
      }
     
      return 0;
    }