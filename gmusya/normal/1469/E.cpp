#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <pair <ll, ll>, ll> pll;

mt19937 gen(time(0));

int modsz = 0, psz = 0;
ll MOD1, MOD2, MOD3;
ll PR;
vector <ll> MOD, P;

void init() {
  MOD.push_back(1000000123);
  MOD.push_back(1000000321);
  MOD.push_back(1000000007);
  MOD.push_back(998244353);
  MOD.push_back(1000000009);
  MOD.push_back(1000000021);
  MOD.push_back(1000000033);
  MOD.push_back(1000000087);
  MOD.push_back(1000000093);
  P.push_back(31);
  P.push_back(97);
  P.push_back(101);
  modsz = MOD.size();
  psz = P.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    do {
      MOD1 = MOD[gen() % modsz];
      MOD2 = MOD[gen() % modsz];
      MOD3 = MOD[gen() % modsz];
    } while (MOD1 == MOD2 || MOD1 == MOD3 || MOD2 == MOD3);
    PR = P[gen() % psz];
    vector <ll> powP1(n + 1), powP2(n + 1), powP3(n + 1);
    powP1[0] = 1, powP2[0] = 1, powP3[0] = 1;
    for (int i = 1; i <= n; i++) {
      powP1[i] = powP1[i - 1] * PR % MOD1;
      powP2[i] = powP2[i - 1] * PR % MOD2;
      powP3[i] = powP3[i - 1] * PR % MOD3;
    }
    for (int i = 1; i <= n; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
      a[i] = 1 - a[i];
    }
    vector <ll> h1(n + 1), h2(n + 1), h3(n + 1);
    for (int i = 1; i <= n; i++) {
      h1[i] = (h1[i - 1] + a[i] * powP1[i]) % MOD1;
      h2[i] = (h2[i - 1] + a[i] * powP2[i]) % MOD2;
      h3[i] = (h3[i - 1] + a[i] * powP3[i]) % MOD3;
    }
    set <pll> s;
    for (int i = k; i <= n; i++) {
      ll curh1 = (h1[i] - h1[i - k] + MOD1) * powP1[n - i] % MOD1;
      ll curh2 = (h2[i] - h2[i - k] + MOD2) * powP2[n - i] % MOD2;
      ll curh3 = (h3[i] - h3[i - k] + MOD3) * powP3[n - i] % MOD3;
      s.insert({{curh1, curh2}, curh3});
    }
    int cnt = 0;
    {
      int tmp = n;
      while (tmp) {
        tmp /= 2;
        cnt++;
      }
    }
    cnt++;
    cnt = min(cnt, k);
    bool flag = false;
    vector <int> arr(k - cnt, 0);
    for (int mask = 0; mask <= n; mask++) {
      ll curh1 = 0, curh2 = 0, curh3 = 0;
      for (int i = cnt - 1; i >= 0; i--) {
        if ((1 << i) & mask) {
          arr.push_back(1);
          curh1 += powP1[k - i];
          curh2 += powP2[k - i];
          curh3 += powP3[k - i];
          if (curh1 >= MOD1)
            curh1 -= MOD1;
          if (curh2 >= MOD2)
            curh2 -= MOD2;
          if (curh3 >= MOD3)
            curh3 -= MOD3;
        } else {
          arr.push_back(0);
        }
      }
      curh1 *= powP1[n - k];
      curh1 %= MOD1;
      curh2 *= powP2[n - k];
      curh2 %= MOD2;
      curh3 *= powP3[n - k];
      curh3 %= MOD3;
      if (s.find({{curh1, curh2}, curh3}) == s.end()) {
        cout << "YES\n";
        flag = true;
        for (auto &now : arr)
          cout << now;
        cout << '\n';
        break;
      }
      for (int i = 0; i < cnt; i++)
        arr.pop_back();
    }
    if (!flag)
      cout << "NO\n";
  }
  return 0;
}