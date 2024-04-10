#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
bool chkMin(T& x, const T& y) {
  return (y < x) ? (x = y, true) : false;
}

template <class T>
void chkMax(T& x, const T& y) {
  if (y > x) x = y;
}

const int N = 100010;
const ll MIN = numeric_limits<ll>::min(), MAX = numeric_limits<ll>::max();

ll sign(ll x) { return x < 0 ? -1 : x == 0 ? 0 : 1; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  uniform_int_distribution<ll> dist((ll)-1e18, (ll)1e18);

  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    //n = 3;
    /*if (n == 1) {
      ll x, y, z;
      scanf("%lld%lld%lld", &x, &y, &z);
      printf("%lld %lld %lld\n", x, y, z);
      continue;
    }*/
    static ll x[N], y[N], z[N];
    for (int i = 0; i < n; ++i) {
      ll b, c;
      scanf("%lld%lld%lld", &x[i], &b, &c);
//      x[i] = dist(rng); b = dist(rng); c = dist(rng);
      y[i] = b + c;
      z[i] = b - c;
    }
    {
      static pair<ll, int> redirect[N];
      for (int i = 0; i < n; ++i) redirect[i] = make_pair(x[i], i);
      sort(redirect, redirect + n);
      function<void(ll*)> reorder = [&](ll* v) {
        static ll tmp[N];
        for (int i = 0; i < n; ++i)
          tmp[i] = v[redirect[i].second];
        memcpy(v, tmp, sizeof(ll) * n);
      };
      reorder(x);
      reorder(y);
      reorder(z);
    }
    ll ansx = 0, ansy = 0, ansz = 0;
    function<bool(ll)> pred = [&](ll r) {
      ll xl = MIN, xr = MAX;
      for (int i = 0; i < n; ++i) {
        chkMax(xl, x[i] - r);
        chkMin(xr, x[i] + r);
      }
      if (xl > xr) return false;

      if (xl == xr) {
        ll yl = MIN, zl = MIN,
           yr = MAX, zr = MAX;
        for (int i = 0; i < n; ++i) {
          ll dist = abs(xl - x[i]);
          chkMax(yl, y[i] - r + dist);
          chkMax(zl, z[i] - r + dist);
          chkMin(yr, y[i] + r - dist);
          chkMin(zr, z[i] + r - dist);
        }
        if (yl <= yr && zl <= zr) {
          ansx = xl;
          ansy = yl;
          ansz = zl;
          //cerr << "ret true\n";
          return true;
        }
        return false;
      }
      // (y/z)*(l/r)*(p/n)
      static ll disc[N];
      int m = 0;
      disc[m++] = xl;
      for (int i = 0; i < n; ++i) if (xl < x[i] && x[i] < xr) disc[m++] = x[i];
      disc[m++] = xr;
      m = unique(disc, disc + m) - disc;
      int pos = 0;
      static ll ylp[N], yln[N], yrp[N], yrn[N], zlp[N], zln[N], zrp[N], zrn[N];
      fill(ylp, ylp + m, MIN);
      fill(yln, yln + m, MIN);
      fill(zlp, zlp + m, MIN);
      fill(zln, zln + m, MIN);
      fill(yrp, yrp + m, MAX);
      fill(yrn, yrn + m, MAX);
      fill(zrp, zrp + m, MAX);
      fill(zrn, zrn + m, MAX);
      for (int i = 0; i < n; ++i) {
        while (pos + 1 < m && disc[pos + 1] <= x[i]) ++pos;
        if (x[i] <= disc[pos]) {
          chkMax(ylp[pos], y[i] - r - x[i]);
          chkMax(zlp[pos], z[i] - r - x[i]);
          chkMin(yrn[pos], y[i] + r + x[i]);
          chkMin(zrn[pos], z[i] + r + x[i]);
        }
        if (x[i] >= disc[pos]) {
          chkMax(yln[pos], y[i] - r + x[i]);
          chkMax(zln[pos], z[i] - r + x[i]);
          chkMin(yrp[pos], y[i] + r - x[i]);
          chkMin(zrp[pos], z[i] + r - x[i]);
        }
      }

      for (int i = 1; i < m; ++i) chkMax(ylp[i], ylp[i - 1]);
      for (int i = 1; i < m; ++i) chkMax(zlp[i], zlp[i - 1]);
      for (int i = 1; i < m; ++i) chkMin(yrn[i], yrn[i - 1]);
      for (int i = 1; i < m; ++i) chkMin(zrn[i], zrn[i - 1]);

      for (int i = m - 2; i >= 0; --i) chkMax(yln[i], yln[i + 1]);
      for (int i = m - 2; i >= 0; --i) chkMax(zln[i], zln[i + 1]);
      for (int i = m - 2; i >= 0; --i) chkMin(yrp[i], yrp[i + 1]);
      for (int i = m - 2; i >= 0; --i) chkMin(zrp[i], zrp[i + 1]);

      function<bool(ll, ll, ll, ll, ll, ll, ll, ll, ll)> check = [&](ll x, ll ylp, ll yln, ll yrp, ll yrn, ll zlp, ll zln, ll zrp, ll zrn) {
        ll yl = MIN, yr = MAX, zl = yl, zr = yr;
        if (ylp != MIN) chkMax(yl, ylp + x);
        if (yln != MIN) chkMax(yl, yln - x);
        if (zlp != MIN) chkMax(zl, zlp + x);
        if (zln != MIN) chkMax(zl, zln - x);

        if (yrp != MAX) chkMin(yr, yrp + x);
        if (yrn != MAX) chkMin(yr, yrn - x);
        if (zrp != MAX) chkMin(zr, zrp + x);
        if (zrn != MAX) chkMin(zr, zrn - x);

        if (yl <= yr && zl <= zr) {
          //cerr << "ans " << yl << ' ' << yr << ' ' << zl << ' ' << zr << ' ' << MIN << ' ' << MAX << '\n';
          ansx = x; ansy = yl; ansz = zl;
          return true;
        }
        return false;
      };

      for (int i = 0; i < m; ++i)
        if (check(disc[i], ylp[i], yln[i], yrp[i], yrn[i], zlp[i], zln[i], zrp[i], zrn[i]))
          return true;
      // prefix : ylp, zlp, yrn, zrn
      function<bool(ll, ll, ll, ll, ll, ll, ll, ll, ll, ll, ll, ll)> checkinter = [&](ll l, ll r, ll k1, ll k2, ll ylp, ll yln, ll yrp, ll yrn, ll zlp, ll zln, ll zrp, ll zrn) {
        if (k1 == MIN || k1 == MAX || k2 == MIN || k2 == MAX) return false;
        k1 -= k2;
        if (sign(k1 + l * 2) * sign(k1 + r * 2) >= 0) return false;
        // y = 2x + k
        // x = -k / 2;
        if (k1 & 1) {
          if (check(-(k1 + 1) / 2, ylp, yln, yrp, yrn, zlp, zln, zrp, zrn)) return true;
          if (check(-(k1 - 1) / 2, ylp, yln, yrp, yrn, zlp, zln, zrp, zrn)) return true;
        } else
          return check(-k1 / 2, ylp, yln, yrp, yrn, zlp, zln, zrp, zrn);
        return false;
      };
      for (int i = 1; i < m; ++i) {
        if (checkinter(disc[i - 1], disc[i], ylp[i - 1], yln[i], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], yrp[i], yrn[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], zlp[i - 1], zln[i], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], zrp[i], zrn[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;

        if (checkinter(disc[i - 1], disc[i], ylp[i - 1], yrn[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], zlp[i - 1], zrn[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], yrp[i - 1], yln[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
        if (checkinter(disc[i - 1], disc[i], zrp[i - 1], zln[i - 1], ylp[i - 1], yln[i], yrp[i], yrn[i - 1], zlp[i - 1], zln[i], zrp[i], zrn[i - 1])) return true;
      }

      return false;
    };
    ll l = 0, r = 3e18;
    while (l < r) {
      ll mid = ((r - l) >> 1) + l;
      if (pred(mid))
        r = mid;
      else
        l = mid + 1;
    }
    //cerr << pred(l) << " predicted\n";

    for (int i = 0; i < n; ++i) {
      ll b = (y[i] + z[i]) / 2, c = (y[i] - z[i]) / 2;
      y[i] = b;
      z[i] = c;
    }

    function<ll(ll, ll, ll)> calc = [&](ll px, ll py, ll pz) {
      ll ret = 0;
      for (int i = 0; i < n; ++i)
        chkMax(ret, abs(px - x[i]) + abs(py - y[i]) + abs(pz - z[i]));
      return ret;
    };

    ll ty = (ansy + ansz) / 2, tz = (ansy - ansz) / 2;
    ansy = ty; ansz = tz;

    ll cur = calc(ansx, ty, tz);
    for (int dy = -1; dy <= 1; ++dy)
      for (int dz = -1; dz <= 1; ++dz)
        if (chkMin(cur, calc(ansx, ty + dy, tz + dz))) {
          ansy = ty + dy;
          ansz = tz + dz;
        }

    /*if (cur > l + 1) {
      cerr << l << " => " << cur << " ==> " << ansx << ' ' << ansy << ' ' << ansz << '\n';
    }*/
    assert(cur <= l + 1);

    printf("%lld %lld %lld\n", ansx, ansy, ansz);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}