#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef __int128 ll;

long long w;

__int128 myabs(__int128 x) {
  if (x < 0)
    return -x;
  return x;
}

bool can(ll m, ll curw) {
  if (curw == 0)
    return (m == 0);
  ll sum = 0, p = 1;
  while (p <= curw) {
    sum += p;
    p *= w;
  }
  if (myabs(m) > sum)
    return false;
  if (can(m - curw, curw / w))
    return true;
  if (can(m + curw, curw / w))
    return true;
  return can(m, curw / w);
}

int main() {
  long long m;
  cin >> w >> m;
  vector <ll> arr;
  arr.push_back(1);
  while (arr.back() <= m)
    arr.push_back(arr.back() * w);
  if (can(m, arr.back()))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}