#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <int> cnt(400'001);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector <int> sum(400'001);
  for (int i = 1; i <= 400'000; i++)
    sum[i] = cnt[i] + sum[i - 1];
  int answer = 20'000'000;
  for (int res = 1; res <= 200'000; res++) {
    int l = res, r = res;
    int cnt = 0, curk = k;
    int it = 0;
    while (curk > 0 && r <= 400'000) {
      int val = sum[r] - sum[l - 1];
      int hm = min(curk, val);
      curk -= hm;
      cnt += it * hm;
      l *= 2;
      r *= 2;
      r++;
      it++;
    }
    if (!curk)
      answer = min(answer, cnt);
  }
  cout << answer;
  return 0;
}