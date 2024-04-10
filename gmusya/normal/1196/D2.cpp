#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <char> c(n + 3);
    for (int i = 3; i <= n + 2; i++) {
      cin >> c[i];
      if (c[i] == 'R')
        c[i] = 'r';
      if (c[i] == 'G')
        c[i] = 'g';
      if (c[i] == 'B')
        c[i] = 'b';
    }
    vector <int> r1(n + 3), g1(n + 3), b1(n + 3);
    vector <int> r2(n + 3), g2(n + 3), b2(n + 3);
    vector <int> r3(n + 3), g3(n + 3), b3(n + 3);
    for (int i = 3; i <= n + 2; i += 3) {
      r3[i] = r3[i - 3], g3[i] = g3[i - 3], b3[i] = b3[i - 3];
      if (c[i] == 'r')
        r3[i]++;
      if (c[i] == 'g')
        g3[i]++;
      if (c[i] == 'b')
        b3[i]++;
    }
    for (int i = 4; i <= n + 2; i += 3) {
      r1[i] = r1[i - 3], g1[i] = g1[i - 3], b1[i] = b1[i - 3];
      if (c[i] == 'r')
        r1[i]++;
      if (c[i] == 'g')
        g1[i]++;
      if (c[i] == 'b')
        b1[i]++;
    }
    for (int i = 5; i <= n + 2; i += 3) {
      r2[i] = r2[i - 3], g2[i] = g2[i - 3], b2[i] = b2[i - 3];
      if (c[i] == 'r')
        r2[i]++;
      if (c[i] == 'g')
        g2[i]++;
      if (c[i] == 'b')
        b2[i]++;
    }
    int ans = n;
    for (int i = 3; i + k - 1 <= n + 2; i += 3) {
      int pos;
      pos = i + k - 1;
      while ((pos - i + 1) % 3)
        pos--;
      { // s[i] == r
        int sum = 0;
        sum += (b3[pos - 2] - b3[i - 3]) + (g3[pos - 2] - g3[i - 3]);
        sum += (b1[pos - 1] - b1[i - 2]) + (r1[pos - 1] - r1[i - 2]);
        sum += (r2[pos] - r2[i - 1]) + (g2[pos] - g2[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'r');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'g');
        ans = min(ans, sum);
      }
      { // s[i] == g
        int sum = 0;
        sum += (b3[pos - 2] - b3[i - 3]) + (r3[pos - 2] - r3[i - 3]);
        sum += (g1[pos - 1] - g1[i - 2]) + (r1[pos - 1] - r1[i - 2]);
        sum += (b2[pos] - b2[i - 1]) + (g2[pos] - g2[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'g');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'b');
        ans = min(ans, sum);
      }
      { // s[i] == b
        int sum = 0;
        sum += (g3[pos - 2] - g3[i - 3]) + (r3[pos - 2] - r3[i - 3]);
        sum += (g1[pos - 1] - g1[i - 2]) + (b1[pos - 1] - b1[i - 2]);
        sum += (b2[pos] - b2[i - 1]) + (r2[pos] - r2[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'b');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'r');
        ans = min(ans, sum);
      }
    }
    for (int i = 4; i + k - 1 <= n + 2; i += 3) {
      int pos;
      pos = i + k - 1;
      while ((pos - i + 1) % 3)
        pos--;
      { // s[i] == r
        int sum = 0;
        sum += (b1[pos - 2] - b1[i - 3]) + (g1[pos - 2] - g1[i - 3]);
        sum += (b2[pos - 1] - b2[i - 2]) + (r2[pos - 1] - r2[i - 2]);
        sum += (r3[pos] - r3[i - 1]) + (g3[pos] - g3[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'r');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'g');
        ans = min(ans, sum);
      }
      { // s[i] == g
        int sum = 0;
        sum += (b1[pos - 2] - b1[i - 3]) + (r1[pos - 2] - r1[i - 3]);
        sum += (g2[pos - 1] - g2[i - 2]) + (r2[pos - 1] - r2[i - 2]);
        sum += (b3[pos] - b3[i - 1]) + (g3[pos] - g3[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'g');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'b');
        ans = min(ans, sum);
      }
      { // s[i] == b
        int sum = 0;
        sum += (g1[pos - 2] - g1[i - 3]) + (r1[pos - 2] - r1[i - 3]);
        sum += (g2[pos - 1] - g2[i - 2]) + (b2[pos - 1] - b2[i - 2]);
        sum += (b3[pos] - b3[i - 1]) + (r3[pos] - r3[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'b');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'r');
        ans = min(ans, sum);
      }
    }
    for (int i = 5; i + k - 1 <= n + 2; i += 3) {
      int pos;
      pos = i + k - 1;
      while ((pos - i + 1) % 3)
        pos--;
      { // s[i] == r
        int sum = 0;
        sum += (b2[pos - 2] - b2[i - 3]) + (g2[pos - 2] - g2[i - 3]);
        sum += (b3[pos - 1] - b3[i - 2]) + (r3[pos - 1] - r3[i - 2]);
        sum += (r1[pos] - r1[i - 1]) + (g1[pos] - g1[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'r');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'g');
        ans = min(ans, sum);
      }
      { // s[i] == g
        int sum = 0;
        sum += (b2[pos - 2] - b2[i - 3]) + (r2[pos - 2] - r2[i - 3]);
        sum += (g3[pos - 1] - g3[i - 2]) + (r3[pos - 1] - r3[i - 2]);
        sum += (b1[pos] - b1[i - 1]) + (g1[pos] - g1[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'g');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'b');
        ans = min(ans, sum);
      }
      { // s[i] == b
        int sum = 0;
        sum += (g2[pos - 2] - g2[i - 3]) + (r2[pos - 2] - r2[i - 3]);
        sum += (g3[pos - 1] - g3[i - 2]) + (b3[pos - 1] - b3[i - 2]);
        sum += (b1[pos] - b1[i - 1]) + (r1[pos] - r1[i - 1]);
        if (pos + 1 <= i + k - 1)
          sum += (c[pos + 1] != 'b');
        if (pos + 2 <= i + k - 1)
          sum += (c[pos + 2] != 'r');
        ans = min(ans, sum);
      }
    }
    cout << ans << endl;
  }
  return 0;
}