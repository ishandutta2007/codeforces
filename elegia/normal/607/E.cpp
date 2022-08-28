#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 50010;
const double EPS = 1e-5, PI = acos(-1);

int n, m;
double a[N], b[N], dist[N], theta[N], srt[N];
int fw[N * 2], vis[N];
pair<double, int> c[N * 2];

void ch(int k, int x) { for (; k <= m * 2; k += k & -k) fw[k] += x; }

int qry(int k) {
  int ret = 0;
  for (; k; k &= k - 1) ret += fw[k];
  return ret;
}

void work(double radius) {
  m = 0;
  for (int i = 1; i <= n; ++i) {
    if (radius <= dist[i]) continue;
    double th = acos(dist[i] / radius);
    double l = theta[i] - th, r = theta[i] + th;
    l = fmod(l, PI * 2); r = fmod(r, PI * 2);
    if (l < 0) l += PI * 2; if (r < 0) r += PI * 2;
    c[++m] = make_pair(l, i);
    c[++m] = make_pair(r, i);
  }
}

long long inters() {
  sort(c + 1, c + m + 1);
  memset(fw, 0, sizeof(fw));
  memset(vis, 0, sizeof(vis));
  //for (int i = 1; i <= m; ++i)
  //  cerr << "(" << c[i].first << ", " << c[i].second << ") ";
  ll ret = 0;
  for (int i = m; i; --i) {
    if (!vis[c[i].second])
      vis[c[i].second] = i;
    ret += qry(vis[c[i].second]);
    ch(i, 1);
    ch(vis[c[i].second], -1);
  }
  //cerr << m << ' ' << ret << '\n';
  return ret;
}

double interdis(int i, int j) {
  // y=a1x+b1, y=a2x+b2, a1x+b1=a2x+b2,
  double x = (b[i] - b[j]) / (a[j] - a[i]);
  double y = a[i] * x + b[i];
  return sqrt(x * x + y * y);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  double x, y;
  cin >> n >> x >> y >> k;
  x *= 1e-3; y *= 1e-3;
  for (int i = 1; i <= n; ++i) {
    double aa, bb;
    cin >> aa >> bb;
    aa *= 1e-3; bb *= 1e-3;
    a[i] = aa;
    b[i] = bb + aa * x - y;
    // f(x + x0) - y
    // cerr << a[i] << "x + " << b[i] << '\n';
    // y = -x/a[i]
    // y = a[i]x + b
    // -x/a[i]=a[i]x+b
    // x = -b/(a[i]+1/a[i])
    // x = -ab/(a^2+1)
    double px = -a[i] * b[i] / (1 + a[i] * a[i]), py = a[i] * px + b[i];
    complex<double> pos(px, py);
    dist[i] = abs(pos);
    //cerr << dist[i] << '\n';
    if (dist[i] > EPS)
      theta[i] = arg(pos);
    else
      theta[i] = atan2(-a[i], 1);
    //cerr << "angle " << theta[i] << '\n';
  }
  double l = 0, r = 1e10, mid;
  while (r - l > EPS) {
    mid = (l + r) / 2;
    work(mid);
    //cerr << mid << ' ';
    if (inters() > k)
      r = mid;
    else
      l = mid;
  }
  work(l);
  ll cnt = inters();
  double ans = (k - cnt) * l;
  map<int, int> rest;
  for (int i = 1; i <= m; ++i) {
    if (vis[c[i].second] == i)
      rest.erase(vis[c[i].second]);
    else {
      auto it = rest.insert(make_pair(vis[c[i].second], c[i].second)).first;
      while (it != rest.begin()) {
        --it;
        ans += interdis(it->second, c[i].second);
      }
    }
  }
  cout << fixed << setprecision(10) << ans;

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}