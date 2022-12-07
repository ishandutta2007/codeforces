#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int a[6] = {1, 2, 3, 4, 6, 12};

int main()
{
  int t;
  cin >> t;
  for (int test = 0; test < t; ++test) {
    string s, ans;
    cin >> s;
    int cnt = 0;
    for (int step = 0; step < 6; ++step) {
      bool flag = false;
      for (int i = 0; i < 12 / a[step]; ++i) {
        bool flag2 = true;
        for (int j = 0; j < a[step]; ++j) {
          if (s[j * (12 / a[step]) + i] != 'X') {
            flag2 = false;
            break;
          }
        }
        if (flag2) {
          flag = true;
          break;
        }
      }
      if (flag) {
        ++cnt;
        ostringstream oss;
        oss << ' ' << a[step] << 'x' << 12 / a[step];
        ans.append(oss.str());
      }
    }
    ans = char(cnt + '0') + ans;
    cout << ans << endl;
  }
  return 0;
}