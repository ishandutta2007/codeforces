#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <chrono>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#ifdef LBT

#define LOG(FMT...) fprintf(stderr, FMT)

#else

#define LOG(FMT...)

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Vec {
	int x, y;
	
	Vec() : x(), y() {}
	
	Vec(int x, int y) : x(x), y(y) {}
	
	Vec(const Vec& v) : x(v.x), y(v.y) {}
	
	Vec operator-() const { return Vec(-x, -y); }
	
	Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
	Vec operator-(const Vec& rhs) const { return *this + -rhs; }

	ll operator^(const Vec& rhs) const { return x * (ll)rhs.x + y * (ll)rhs.y; }
	ll operator*(const Vec& rhs) const { return x * (ll)rhs.y - y * (ll)rhs.x; }
	
	bool operator==(const Vec& rhs) const { return x == rhs.x && y == rhs.y; }
	
	ll norm() const { return x * (ll)x + y * (ll)y; }
};


bool cmpX(const Vec& lhs, const Vec& rhs) { return lhs.x < rhs.x; }

vector<Vec> hull(const vector<Vec>& seq, int sign) {
	vector<Vec> ret;
	int n = seq.size(), top = 0;
	for (int i = 0; i < n; ++i) {
		if (!ret.empty() && seq[i].x == ret.back().x)
			if ((seq[i].y - ret[top - 1].y) * sign >= 0) {
				ret.pop_back();
				--top;
			} else
				continue;
		while (top > 1 && (ret[top - 1] - ret[top - 2]) * (seq[i] - ret[top - 1]) * sign >= 0) {
			ret.pop_back();
			--top;
		}
		ret.push_back(seq[i]);
		++top;
	}
	return ret;
}

vector<Vec> convex(vector<Vec> seq) {
	vector<Vec> a = hull(seq, 1), b = hull(seq, -1);
	reverse(a.begin(), a.end());
	a.insert(a.end(), b.begin(), b.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	if (a.size() > 1 && a.front() == a.back())
		a.pop_back();
	return a;
}

const int N = 2010;

int n;
int ans[N];
bool vis[N];
char s[N];
Vec v[N], reord[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &v[i].x, &v[i].y);
  scanf("%s", s + 1);
  vector<Vec> seq(v + 1, v + n + 1);
  sort(seq.begin(), seq.end(), cmpX);
  vector<Vec> c = convex(seq);
  Vec anch = c.back();
  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j <= n; ++j)
      if (v[j] == anch) {
        ans[i] = j;
        break;
      }
    int cur = 0;
    for (int j = 0; j < c.size(); ++j)
      if (c[j] == anch) {
        cur = j;
        break;
      }
    Vec ng;
    if (s[i] == 'L') {
      ng = c[(cur + 1) % c.size()];
    } else
      ng = c[(cur + c.size() - 1) % c.size()];
    for (int j = 0; j < seq.size(); ++j)
      if (seq[j] == anch) {
        seq.erase(seq.begin() + j, seq.begin() + j + 1);
        break;
      }
    c = convex(seq);
    anch = ng;
  }
  for (int j = 1; j <= n; ++j)
    if (v[j] == anch) {
      ans[n - 1] = j;
      break;
    }
  for (int i = 1; i < n; ++i) {
    printf("%d ", ans[i]);
    vis[ans[i]] = true;
  }
  for (int j = 1; j <= n; ++j)
    if (!vis[j])
      printf("%d\n", j);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}