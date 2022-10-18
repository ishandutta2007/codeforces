#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int ADD = 100005;
vector<int> who[2 * ADD + 5];
int ans[100005];

vector<char> cQ;
vector<int> xQ;

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    who[a + ADD].push_back(i);
  }

  for (int i = 0; i < q; ++i) {
    char c; int x;
    cin >> c >> x;
    cQ.push_back(c);
    xQ.push_back(x);
    // cout << c << " " << x << endl; 
  }

  int curRange = ADD - 2, flip = 1;
  for (int i = q - 1; i >= 0; --i) {
    if (cQ[i] == '>' && xQ[i] <= 0 || cQ[i] == '<' && xQ[i] >= 0) {
      int x = abs(xQ[i]);
      int sgn = cQ[i] == '>' && xQ[i] <= 0 ? -1 : +1;
      sgn *= flip;
      // cout << curRange << " " << x << endl;
      while (curRange >= x) {
        for (int pos : who[curRange + ADD]) {
          ans[pos] = sgn * curRange;
        }
        for (int pos : who[-curRange + ADD]) {
          ans[pos] = sgn * curRange;
        }
        curRange--;
      }
      flip *= -1;
    } else {
      int x = abs(xQ[i]) + 1;
      int sgn = xQ[i] < 0 ? +1 : -1;
      sgn *= flip;
      while (curRange >= x) {
        for (int pos : who[curRange + ADD]) {
          ans[pos] = sgn * curRange;
        }
        // cout << curRange + ADD << endl;
        for (int pos : who[-curRange + ADD]) {
          ans[pos] = sgn * curRange;
        }
        curRange--;
      }
    }
  }

  while (curRange >= 0) {
    for (int pos : who[curRange + ADD]) {
      ans[pos] = flip * curRange;
    }
    for (int pos : who[-curRange + ADD]) {
      ans[pos] = flip * -curRange;
    }
    curRange--;
  }

  for (int i = 0; i < n; ++i)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}