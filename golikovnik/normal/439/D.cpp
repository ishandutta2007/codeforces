#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int m_a = 1e9 + 20;

  for (int& x : a) {
    cin >> x;
    m_a = min(m_a, x);
  }

  vector<int> b(m);
  int m_b = 0;

  for (int& x : b) {
    cin >> x;
    m_b = max(m_b, x);
  }

  if (m_a >= m_b) {
    cout << "0\n";
    return 0;
  }

  auto calc = [&](int x) {
    long long result = 0;
    for (int y : a) {
      result += max(0, x - y);
    }
    for (int y : b) {
      result += max(0, y - x);
    }
    return result;
  };

  int left = m_a - 1;
  int right = m_b;
  while (left + 1 != right) {
    auto middle = (left + right) / 2;
    if (calc(middle + 1) > calc(middle)) {
      right = middle;
    } else {
      left = middle;
    }
  }
  long long answer = 1e18;
  for (int k = left - 1; k <= right + 1; ++k) {
    answer = min(answer, calc(k));
  }
  cout << answer << '\n';
  return 0;  
}