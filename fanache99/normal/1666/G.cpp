#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

struct ufds {
  int n;
  vector<int> p;
  vector<ld> a, b, c;
  ufds(int n = 0) : n(n), p(n), a(n), b(n), c(n) {
    for (int i = 0; i < n; i++)
      p[i] = i;
  }
  int findSet(int i) {
    return p[i] == i ? i : (p[i] = findSet(p[i]));
  }
  bool inSameSet(int i, int j) {
    return findSet(i) == findSet(j);
  }
  ld evaluate(int i, ld z) {
    i = findSet(i);
    return a[i] * z * z + b[i] * z + c[i];
  }
  void add(int i, ld aa, ld bb, ld cc) {
    i = findSet(i);
    a[i] += aa, b[i] += bb, c[i] += cc;
  }
  void unionSet(int i, int j) {
    i = findSet(i); j = findSet(j);
    if (i != j) {
      a[i] += a[j], b[i] += b[j], c[i] += c[j];
      p[j] = i;
    }
  }
};


struct point {
  ld x, y, z;
  point operator+(point & o) {
    return {x - o.x, y - o.y, z - o.z};
  }
  point operator-(point & o) {
    return {x - o.x, y - o.y, z - o.z};
  }
  point operator*(ld f) {
    return {x * f, y * f, z * f};
  }
  ld length() {
    return sqrt(x * x + y * y + z * z);
  }
};

point cross(point a, point b) {
  return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

struct event {
  int i, z;
  ld a, b, c;
  event(int i, int z, ld a, ld b, ld c): i(i), z(z), a(a), b(b), c(c) {}
  bool operator<(const event o) const {
    return z < o.z;
  }
};

int n, m, q, h[100100], qp[100100], o[100100];
ld res[100100];
point p[100100];
vector<int> e[100100];
vector<event> ev;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  vector<int> op;
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y >> p[i].z, op.push_back(i);
  sort(op.begin(), op.end(), [&](int i, int j) {return p[i].z < p[j].z;});
  cin >> m;
  for (int i = 0; i < m; i++) {
    int f[3];
    for (int j = 0; j < 3; j++)
      cin >> f[j], f[j]--;
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        if (j != k)
          e[f[j]].push_back(f[k]);
    sort(f, f + 3, [&](int j, int k) { return p[j].z < p[k].z; });
    ld z2 = p[f[2]].z, z1 = p[f[1]].z, z0 = p[f[0]].z;
    if (z2 != z0) {
      point mp = (p[f[2]] - p[f[0]]) * ((z1 - z0) / (z2 - z0));
      if (z0 < z1) {
        ld ar = cross(mp, p[f[1]] - p[f[0]]).length() / 2;
        ld d = z1 - z0;
        ld ad = ar / d / d;
        ld a = -ad, b = ad * 2 * z0, c = ar - ad * z0 * z0;
        ev.emplace_back(f[1], z1, a, b, c);
        ev.emplace_back(f[1], z0, -a, -b, -c + ar);
      }
      if (z1 < z2) {
        ld ar = cross(p[f[2]] - p[f[0]] - mp, p[f[1]] - p[f[2]]).length() / 2;
        ld d = z2 - z1;
        ld ad = ar / d / d;
        ld a = ad, b = -ad * 2 * z2, c = ad * z2 * z2;
        ev.emplace_back(f[2], z2, a, b, c);
        ev.emplace_back(f[2], z1, -a, -b, -c + ar);
      }
    } else {
      ld ar = cross(p[f[2]] - p[f[0]], p[f[1]] - p[f[0]]).length() / 2;
      ev.emplace_back(f[2], z2, 0, 0, ar);
    }
  }
  sort(ev.begin(), ev.end());
  cin >> q;
  for (int i = 0; i < q; i++)
    cin >> h[i] >> qp[i], qp[i]--, o[i] = i;
  sort(o, o + q, [&](int i, int j) { return h[i] > h[j]; });
  ufds u(n);
  for (int ii = 0; ii < q; ii++) {
    int i = o[ii];
    int z = h[i];
    while (!op.empty() && p[op.back()].z > z) {
      int j = op.back();
      for (int k : e[j])
        if (p[k].z > z)
          u.unionSet(j, k);
      op.pop_back();
    }
    while (!ev.empty() && ev.back().z > z) {
      u.add(ev.back().i, ev.back().a, ev.back().b, ev.back().c);
      ev.pop_back();
    }
    if (p[qp[i]].z <= z)
      res[i] = -1;
    else
      res[i] = u.evaluate(qp[i], z);
  }
  for (int i = 0; i < q; i++)
    if (res[i] < -0.5)
      cout << "-1\n";
    else
      cout << res[i] << "\n";
}