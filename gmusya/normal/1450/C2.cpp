#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void change(vector <vector <char>> &c, int k, char s) {
  int n = (int) c.size();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if ((i + j) % 3 != k)
        continue;
      if (s == 'O' && c[i][j] == s)
        c[i][j] = 'X';
      if (s == 'X' && c[i][j] == s)
        c[i][j] = 'O';
    }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <vector <char>> c(n, vector <char>(n));
    int vala0 = 0, vala1 = 0, vala2 = 0;
    int valb0 = 0, valb1 = 0, valb2 = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        cin >> c[i][j];
        if (c[i][j] == 'X') {
          if ((i + j) % 3 == 0)
            vala0++;
          if ((i + j) % 3 == 1)
            vala1++;
          if ((i + j) % 3 == 2)
            vala2++;
        }
        if (c[i][j] == 'O') {
          if ((i + j) % 3 == 0)
            valb0++;
          if ((i + j) % 3 == 1)
            valb1++;
          if ((i + j) % 3 == 2)
            valb2++;
        }
      }
    vector <pair <int, pair <int, int>>> tmp;
    tmp.push_back({vala0 + valb1, {0, 1}});
    tmp.push_back({vala0 + valb2, {0, 2}});
    tmp.push_back({vala1 + valb0, {1, 0}});
    tmp.push_back({vala1 + valb2, {1, 2}});
    tmp.push_back({vala2 + valb0, {2, 0}});
    tmp.push_back({vala2 + valb1, {2, 1}});
    sort(tmp.begin(), tmp.end());
    change(c, tmp[0].second.first, 'X');
    change(c, tmp[0].second.second, 'O');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << c[i][j];
      cout << '\n';
    }
  }
  return 0;
}