#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long lcm(long long a, long long b) {return a / gcd(b, a) * b;}

bool isPrime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    long long p, q;
    int prime = n + 1;
    while (!isPrime(prime)) --prime;
    // cout << prime << endl;
    p = prime - 2; q = 2 * prime;
    int gr = prime + 1;
    while (!isPrime(gr)) ++gr;
    long long P, Q = lcm(q, 1LL * prime * gr);
    P = 1LL * p * (Q / q) + 1LL * (n - prime + 1) * (Q / prime / gr);
    long long G = gcd(P, Q);
    p = P / G; q = Q / G;
    cout << p << "/" << q << endl;
  }
  return 0;
}