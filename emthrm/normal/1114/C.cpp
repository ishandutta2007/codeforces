#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
// https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/prime_factorization.cpp
vector<pair<long long, long long> > prime_factorize(long long n) {
  vector<pair<long long, long long> > res;
  for (long long p = 2; p * p <= n; ++p) {
    if (n % p != 0) continue;
    int num = 0;
    while (n % p == 0) { ++num; n /= p; }
    res.push_back(make_pair(p, num));
  }
  if (n != 1) res.push_back(make_pair(n, 1));
  return res;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n, b; cin >> n >> b;
  auto res = prime_factorize(b);
  long long ans = LINF;
  for (auto a : res) {
    long long tmp = 0, moto = a.first;
    // cout << a.first << " " << a.second << '\n';
    while (a.first <= n) {
      tmp += n / a.first;
      // cout << a.first << " " << tmp << '\n';
      if (n / moto < a.first) break;
      a.first *= moto;
    }
    tmp /= a.second;
    ans = min(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}