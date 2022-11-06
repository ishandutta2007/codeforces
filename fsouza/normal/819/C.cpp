#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

void read(lint &result, vector<int> *primes = nullptr) {
  result = 1;
  for (int rep = 0; rep < 3; ++rep) {
    int value;
    scanf("%d", &value);
    result *= value;
    if (primes != nullptr) {
      for (int p = 2; p * p <= value; ++p)
        if (value % p == 0) {
          primes->push_back(p);
          do {
            value /= p;
          } while (value % p == 0);
        }
      if (value != 1) {
        primes->push_back(value);
        value = 1;
      }
    }
  }
  if (primes != nullptr) {
    sort(primes->begin(), primes->end());
    primes->resize(unique(primes->begin(), primes->end()) - primes->begin());
  }
}

lint solve(lint x, lint y, lint m, vector<int> &primes) {
  vector<lint> dontmults;
  for (int p : primes) {
    lint pexp = 1;
    while (pexp <= x / p && y % (pexp * p) == 0) {
      pexp *= p;
      if (m % pexp != 0)
        break;
    }
    if (m % pexp != 0) {
      dontmults.push_back(pexp);
    }
  }
  lint result = 0;
  for (int s = 0; s < (1 << dontmults.size()); ++s) {
    lint mult = 1;
    for (int i = 0; i < (int)dontmults.size(); ++i)
      if (s & (1<<i)) {
        if (mult <= x / dontmults[i]) mult *= dontmults[i];
        else mult = x + 1;
      }
    if (__builtin_popcount(s) % 2 == 0) result += x / mult;
    else result -= x / mult;
  }
  return result;
}

vector<lint> get_divisors(lint num, vector<int> &primes) {
  vector<lint> result = {1};
  for (int p : primes)
    if (num % p == 0) {
      const int prev_result_size = result.size();
      lint pexp = 1;
      do {
        pexp *= p;
        num /= p;
        for (int i = 0; i < prev_result_size; ++i)
          result.push_back(result[i] * pexp);
      } while (num % p == 0);
    }
  return result;
}

lint divisors_up_to(lint m, lint limit, vector<int> &primes) {
  lint m0 = 1, m1 = 1;
  for (int i = (int)primes.size() - 1; i >= 0; --i)
    if (m % primes[i] == 0) {
      if (m0 <= m1) {
        do {
          m /= primes[i];
          m0 *= primes[i];
        } while (m % primes[i] == 0);
      } else {
        do {
          m /= primes[i];
          m1 *= primes[i];
        } while (m % primes[i] == 0);
      }
    }
  vector<lint> divm0 = get_divisors(m0, primes);
  vector<lint> divm1 = get_divisors(m1, primes);
  if (divm1.size() < divm0.size()) swap(divm0, divm1);
  sort(divm1.begin(), divm1.end());
  lint result = 0;
  for (lint div0 : divm0) {
    result +=
        upper_bound(divm1.begin(), divm1.end(), limit / div0) - divm1.begin();
  }
  return result;
}

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    lint y, x, s;
    vector<int> y_primes;
    read(y, &y_primes);
    read(x);
    vector<int> m_primes;
    read(s, &m_primes);
    const lint m = 2 * s;
    if (find(m_primes.begin(), m_primes.end(), 2) == m_primes.end())
      m_primes.insert(m_primes.begin(), 2);
    lint result = solve(x, y, m, y_primes) + divisors_up_to(m, y, m_primes);
    printf("%lld\n", result);
  }

  return 0;
}