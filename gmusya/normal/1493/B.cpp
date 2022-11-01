#include <iostream>
#include <vector>
#include <string>

using namespace std;

int mirror(int x) {
  switch (x) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 5;
    case 5: return 2;
    case 8: return 8;
    default: return -1;
  }
}

int h, m;

bool correct(int h_cur, int m_cur) {
  int a = h_cur / 10;
  int b = h_cur % 10;
  int c = m_cur / 10;
  int d = m_cur % 10;
  a = mirror(a);
  b = mirror(b);
  c = mirror(c);
  d = mirror(d);
  if (a == -1 || b == -1 || c == -1 || d == -1)
    return false;
  int h_new = d * 10 + c;
  int m_new = b * 10 + a;
  return h_new < h && m_new < m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> h >> m;
    int h_cur, m_cur;
    {
      string s;
      cin >> s;
      h_cur = (s[0] - '0') * 10 + (s[1] - '0');
      m_cur = (s[3] - '0') * 10 + (s[4] - '0');
    }
    while (!correct(h_cur, m_cur)) {
      m_cur++;
      if (m_cur == m) {
        h_cur++;
        m_cur = 0;
      }
      if (h_cur == h)
        h_cur = 0;
    }
    cout << h_cur / 10 << h_cur % 10 << ':' << m_cur / 10 << m_cur % 10 << '\n';
  }
  return 0;
}