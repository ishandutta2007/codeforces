// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;


typedef __int128 int128;
istream& operator>>(istream& in, int128& n) {
  string s;
  in >> s;
  n = 0;
  for (char c : s) {
    n *= 10;
    n += c - '0'; 
  }     
  return in;
}

ostream& operator<<(ostream& out, int128 n) {
  if (n == 0) {
    out << 0;
    return out;
  }
  string res;
  bool neg = n < 0;
  while (n > 0) {
    res += char('0' + n % 10);
    n /= 10;
  }
  if (neg) {
    res += '-';
  }
  reverse(res.begin(), res.end());
  out << res;    
  return out;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, K;
    long long X;
    string S;
    cin >> N >> K >> X >> S;
    vector<int> add;
    --X;
    if (count(S.begin(), S.end(), '*') == 0) {
      cout << S << '\n';
      continue;
    }

    vector<int> ct;
    string new_S;
    for (int i = 0; i < N; ++i) {
      new_S += S[i];
      if (S[i] == '*') {   
        if (i == 0 || S[i - 1] == 'a') {
          ct.push_back(1);
        } else {
          ct.back() += 1;
          new_S.pop_back();
        }
      } 
    }

    debug(ct, new_S);
    for (auto& e : ct) {
      (e *= K) += 1;
    }
    int s = int(ct.size());
    vector<long long> cr(s + 1, X + 1);
    cr[0] = 1;
    reverse(ct.begin(), ct.end());
    for (int i = 0; i < s; ++i) {
      if ((int128) cr[i] * ct[i] > X) {
        break;
      }
      cr[i + 1] = cr[i] * ct[i];
    }

    debug(cr);
    vector<int> r(s);
    for (int i = s - 1; i >= 0; --i) {
      r[i] = X / cr[i];
      X %= cr[i];
    }

    debug(r);
    string ans;
    for (int i = 0, p = s - 1; i < int(new_S.size()); ++i) {
      if (new_S[i] == '*') {
        ans += string(r[p], 'b');
        --p;
      } else {
        ans += 'a';
      }
    }   
    cout << ans << '\n';
  }
}