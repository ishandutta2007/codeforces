#include <iostream>
#include <vector>

using namespace std;

bool flag = false;

void change(vector <vector <char>> &c, int k, char s) {
  if (flag)
    return;
  flag = true;
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
    flag = false;
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
    vala0 = -vala0, vala1 = -vala1, vala2 = -vala2;
    if (vala0 >= vala1 && vala0 >= vala2)
      change(c, 0, 'X');
    if (vala1 >= vala0 && vala1 >= vala2)
      change(c, 1, 'X');
    if (vala2 >= vala0 && vala2 >= vala1)
      change(c, 2, 'X');
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << c[i][j];
      cout << '\n';
    }
  }
  return 0;
}