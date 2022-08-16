#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int sum(string s, int n) {
  bool same = true;
  for(int i = 1; i < s.size(); i++) same &= s[i - 1] == s[i];
  if(n == 1 && same) s.back()++, --n;
  int ret = 0;
  for(int i = 0; i < 128; i++) ret = max< int >(ret, count(begin(s), end(s), i));
  return ret + min((int) s.size() - ret, n);
}

int main() {
  int N;
  string S[3];
  cin >> N;
  for(int i = 0; i < 3; i++) cin >> S[i];
  int t[3] = {sum(S[0], N), sum(S[1], N), sum(S[2], N)};
  int s = max(t[0], max(t[1], t[2]));
  if(count(t, t + 3, s) > 1) cout << "Draw" << endl;
  else if(s == t[0]) cout << "Kuro" << endl;
  else if(s == t[1]) cout << "Shiro" << endl;
  else cout << "Katie" << endl;
}