#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


int ask(int c, int d) {
  cout << "? " << c << " " << d << endl;
  int k; //= ans(c, d);
  cin >> k;
  return k;
}

void dfs(int p, int bit, int c, int d) {

  if(bit == -1) {
    cout << "! " << c << " " << d << endl;
    return;
  }

  if(p) {
    int cc = c | (1 << bit);
    int dd = d;

    int pp = ask(cc, dd);

    if(pp <= 0) {
      int qq = ask(cc, dd ^ (1 << bit));
      if(qq >= 0) {
        dd |= 1 << bit;
        dfs(true, bit - 1, cc, dd);
      }  else {
        dfs(false, bit - 1, cc, dd);
      }
    } else {
      int qq = ask(cc ^ (1 << bit), dd | (1 << bit));
      if(qq > 0) {
        dfs(true, bit - 1, cc, dd);
      } else {
        dfs(true, bit - 1, cc ^ (1 << bit), dd);
      }
    }

  } else {

    int cc = c;
    int dd = d | (1 << bit);

    int pp = ask(cc, dd) * -1;

    if(pp == 0) {
      dfs(false, bit - 1, cc, dd);
    } else if(pp == -1) {
      int qq = ask(cc ^ (1 << bit), dd) * -1;
      if(qq >= 0) {
        cc |= 1 << bit;
        dfs(false, bit - 1, cc, dd);
      } else {
        dfs(true, bit - 1, cc, dd);
      }
    } else {
      int qq = ask(cc | (1 << bit), dd ^ (1 << bit)) * -1;
      if(qq > 0) {
        dfs(false, bit - 1, cc, dd);
      } else {
        dfs(false, bit - 1, cc, dd ^ (1 << bit));
      }
    }
  }
}

int main() {
  int p = ask(0, 0);
  dfs(p >= 0, 29, 0, 0);
}