#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
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

const int N = 52;

int a[N], d[N];
pair<int, int> v[N];
ull mask[N];
int orientation[N];
char s[N][N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  fill(d, d + n, n - 1);
  for (int i = 0; i < n; ++i)
    mask[i] = ((1ull << n) - 1) ^ (1ull << i);
  for (int i = 0; i < n; ++i)
    memset(s[i], '0', n * sizeof(char));
  for (int rep = 0; rep < m; ++rep) {
    int i, j;
    scanf("%d%d", &i, &j);
    --i; --j;
    mask[i] ^= 1ull << j;
    mask[j] ^= 1ull << i;
    ++a[j];
    --d[i]; --d[j];
    s[i][j] = '1';
  }
  while (m < n * (n - 1) / 2) {
    ++m;
    ull vis = 0, que = 0;
    for (int i = 0; i < n; ++i)
      v[i] = make_pair(a[i], i);
    sort(v, v + n);
    memset(orientation, -1, sizeof(orientation));
    for (int rep = 0; rep < n; ++rep) {
      que |= 1ull << v[rep].second;
      while (que != vis) {
        int i = __builtin_ctzll(que ^ vis);
        if (d[i]) {
          for (int j = 0; j < n; ++j)
            if ((mask[i] >> j) & 1 & (mask[j] >> i)) {
              mask[i] ^= 1ull << j;
              --d[i]; --d[j];
              s[j][i] = '1';
              break;
            }
          while (orientation[i] != -1) {
            mask[i] ^= 1ull << orientation[i];
            mask[orientation[i]] ^= 1ull << i;
            s[i][orientation[i]] = '1';
            s[orientation[i]][i] = '0';
            i = orientation[i];
          }
          ++a[i];
          goto DONE;
        }
        ull nw = mask[i] & ~que;
        while (nw) {
          int j = __builtin_ctzll(nw);
          nw ^= 1ull << j;
          orientation[j] = i;
        }
        que |= mask[i];
        vis |= 1ull << i;
      }
    }
    DONE:;
  }
  for (int i = 0; i < n; ++i)
    puts(s[i]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}