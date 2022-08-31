#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


string s;
int is_p[2000][2000];

bool add(int l, int r) {
  if(l > r) return true;
  if(l == r) return true;
  if(~is_p[l][r]) return is_p[l][r];
  if(s[l] != s[r]) return false;
  return is_p[l][r] = add(l + 1, r - 1);
}

int main() {
  memset(is_p, -1, sizeof(is_p));

  cin >> s;
  int N = (int) s.size();
  int rs[2000] = {}, ls[2000] = {};
  for(int i = 0; i < N; i++) {
    for(int j = i; j < N; j++) {
      if(add(i, j)) {
        rs[i]++, ls[j]++;
      }
    }
  }
  for(int i = N - 2; i >= 0; i--) {
    rs[i] += rs[i + 1];
  }
  for(int i = 1; i < N; i++) {
    //ls[i] += ls[i - 1];
  }
  int64 ret = 0;
  for(int i = 0; i + 1 < N; i++) {
    ret += 1LL * rs[i + 1] * ls[i];
  }
  cout << ret << endl;
}