// September 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      d[i] = c - '0';
    }
    vector<int> mark(n, -1);
    bool solved = false;
    for (int first2 = 0; first2 < 10; first2++) {
      int last_pos = -1;
      for (int i = 0; i < n; i++) {
        if (d[i] < first2) {
          last_pos = i;
        }
      }
      int last = -1;
      bool works = true;
      for (int i = 0; i < n; i++) {
        if (d[i] < first2) {
          if (d[i] < last) {
            works = false;
          }
          mark[i] = first2;
          last = d[i];
        } else if (d[i] == first2 && i > last_pos) {
          mark[i] = first2;
          last = d[i];
        }
      }
      last = -1;
      for (int i = 0; i < n; i++) {
        if (mark[i] != first2) {
          if (d[i] < last) {
            works = false;
          }
          last = d[i];
        }
      }
      if (works) {
        for (int i = 0; i < n; i++) {
          cout << (mark[i] == first2 ? 1 : 2);
        }
        cout << '\n';
        solved = true;
        break;
      }
    }
    if (!solved) {
      cout << "-\n";
    }
  }


  return 0;
}