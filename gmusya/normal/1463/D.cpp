#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <bool> flag(2 * n);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      flag[x] = true;
    }
    vector <int> a, b;
    for (int i = 0; i < 2 * n; i++) {
      if (flag[i])
        a.push_back(i);
      else
        b.push_back(i);
    }
    int lbin = 0, rbin = n;
    while (lbin != rbin) {
      int mbin = (lbin + rbin + 1) / 2;
      bool flag = true;
      for (int i = 0; i < mbin; i++)
        if (b[i] > a[n - mbin + i])
          flag = false;
      if (flag)
        lbin = mbin;
      else
        rbin = mbin - 1;
    }
    int maxx = lbin;
    lbin = 0, rbin = n;
    while (lbin != rbin) {
      int mbin = (lbin + rbin) / 2;
      bool flag = true;
      for (int i = 0; i + mbin < n; i++)
        if (b[i + mbin] < a[i])
          flag = false;
      if (flag)
        rbin = mbin;
      else
        lbin = mbin + 1;
    }
    int minx = lbin;
    cout << maxx - minx + 1 << '\n';
  }
  return 0;
}