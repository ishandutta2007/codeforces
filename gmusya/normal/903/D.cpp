#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef __int128 i128;

int main() {
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  map <ll, ll> m;
  i128 sum = 0;
  i128 ans = 0;
  for (int i = 0; i < n; i++) {
    i128 cursum = sum;
    i128 cnt = i;
    cursum -= m[a[i] - 1] * (a[i] - 1);
    cursum -= m[a[i]] * a[i];
    cursum -= m[a[i] + 1] * (a[i] + 1);
    cnt -= m[a[i] - 1];
    cnt -= m[a[i]];
    cnt -= m[a[i] + 1];
    ans += cnt * a[i] - cursum;
    m[a[i]]++;
    sum += a[i];
  }
  vector <int> answer;
  if (ans < 0) {
    cout << '-';
    ans = -ans;
  }
  while (ans) {
    answer.push_back(ans % 10);
    ans /= 10;
  }
  if (answer.empty())
    answer.push_back(0);
  reverse(answer.begin(), answer.end());
  for (auto &now : answer)
    cout << now;
  return 0;
}