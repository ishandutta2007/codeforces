/*
 * author:  ADMathNoob
 * created: 02/28/21 08:33:49
 * problem: https://codeforces.com/contest/1491/problem/F
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491F.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491F.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491F.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

int Ask(vector<int> a, vector<int> b) {
  cout << "? " << a.size() << ' ' << b.size() << endl;
  for (int i = 0; i < (int) a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i] + 1;
  }
  cout << endl;
  for (int i = 0; i < (int) b.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << b[i] + 1;
  }
  cout << endl;
  int res;
  cin >> res;
  return res;
}

vector<int> Get(int ll, int rr) {
  vector<int> res(rr - ll + 1);
  iota(res.begin(), res.end(), ll);
  return res;
}

int main() {
  //   ios::sync_with_stdio(0);
  //   cin.tie(0);

  // #ifdef _DEBUG
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  //   freopen("debug_output.txt", "w", stderr);
  // #endif

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int magnet = -1;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
      int res = Ask(Get(0, i - 1), Get(i, i));
      if (res != 0) {
        magnet = i;
        int low = 0, high = i - 1;
        while (low < high) {
          int mid = (low + high) >> 1;
          if (Ask(Get(low, mid), Get(i, i)) != 0) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        for (int j = 0; j < i; j++) {
          if (j != low) {
            ans.push_back(j);
          }
        }
        break;
      }
    }
    for (int i = magnet + 1; i < n; i++) {
      if (Ask(Get(magnet, magnet), Get(i, i)) == 0) {
        ans.push_back(i);
      }
    }
    cout << "! " << ans.size();
    for (int x : ans) {
      cout << ' ' << x + 1;
    }
    cout << endl;
  }

  return 0;
}