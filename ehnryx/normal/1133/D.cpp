#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long> a;
  vector<long> b;
  map<pair<long, long>, int> freq;
  for (int i = 0; i < n; i++) {
    long ai;
    cin >> ai;
    a.emplace_back(ai);
  }
  for (int i = 0; i < n; i++) {
    long bi;
    cin >> bi;
    b.emplace_back(bi);
  }
  int bonus = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) {
      bool neg = (long long) b[i] * a[i] < 0;
      long factor = abs(gcd(b[i], a[i]));
      pair <long, long> frac;
      long num = (neg) ? (-1 * abs(b[i] / factor)) : abs(b[i] / factor);
      long den = abs(a[i] / factor);
      frac = make_pair(num, den);
      freq[frac]++;
    } else if (b[i] == 0) {
        bonus++;
    }
  }
  int maxsf = 0;
  for (auto it : freq) {
    maxsf = max(maxsf, it.second);
  }
  cout << maxsf + bonus << endl;
  return 0;
}