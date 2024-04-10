#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <unordered_set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int P = 998244353, A = 62;

int mp[256];
int cnt[A][A];
ll angle[A][A][A];
short store[A][A][A];
unordered_set<string> words[11];

int norm(int x) { return x >= P ? x - P : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < P) x += P; }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, a = 0;
  scanf("%d", &n);
  for (char c = 'a'; c <= 'z'; ++c) mp[c] = c - 'a';
  for (char c = 'A'; c <= 'Z'; ++c) mp[c] = 26 + (c - 'A');
  for (char c = '0'; c <= '9'; ++c) mp[c] = 52 + (c - '0');
  while (n--) {
    string s;
    cin >> s;
    words[s.size()].insert(s);
    reverse(s.begin(), s.end());
    words[s.size()].insert(s);
    a = max({a, mp[s.front()], mp[s.back()]});
  }
  int ans = 0;
  for (int len = 3; len <= 10; ++len) {
    if (words[len].empty()) continue;
    memset(cnt, 0, sizeof(cnt));
    for (const auto& str : words[len])
      ++cnt[mp[str.front()]][mp[str.back()]];
    for (int i = 0; i <= a; ++i)
      for (int j = 0; j <= a; ++j) {
        memset(angle[i][j], 0, sizeof(ll) * (a + 1));
        memset(store[i][j], 0, sizeof(short) * (a + 1));
      }
    for (int i = 0; i <= a; ++i)
      for (int j = 0; j <= a; ++j)
        for (int k = j; k <= a; ++k)
          for (int l = k; l <= a; ++l) {
            angle[j][k][l] += cnt[i][j] * (ll)cnt[i][k] * cnt[i][l];
            if (++store[j][k][l] == 9000) {
              angle[j][k][l] %= P;
              store[j][k][l] = 0;
            }
          }
    for (int i = 0; i <= a; ++i)
      for (int j = 0; j <= a; ++j)
        for (int k = 0; k <= a; ++k)
          angle[i][j][k] %= P;
    for (int i = 0; i <= a; ++i) {
      {
        int j = i;
        {
          int k = j;
          {
            int l = k;
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l]) % P;
          }
          for (int l = k + 1; l <= a; ++l) {
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] * 4) % P;
          }
        }
        for (int k = j + 1; k <= a; ++k) {
          {
            int l = k;
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 6) % P;
          }
          for (int l = k + 1; l <= a; ++l) {
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 12) % P;
          }
        }
      }
      for (int j = i + 1; j <= a; ++j) {
        {
          int k = j;
          {
            int l = k;
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 4) % P;
          }
          for (int l = k + 1; l <= a; ++l) {
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 12) % P;
          }
        }
        for (int k = j + 1; k <= a; ++k) {
          {
            int l = k;
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 12) % P;
          }
          for (int l = k + 1; l <= a; ++l) {
            ans = (ans + angle[i][j][k] * angle[j][k][l] % P * angle[i][k][l] % P *
                         angle[i][j][l] % P * 24) % P;
          }
        }
      }
    }
  }
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}