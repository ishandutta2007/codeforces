//fixing https://codeforces.com/contest/1326/submission/115196286
//I think it is a hashing hack
//choose uncommon / random bases and modulos to prevent this

#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int N = (int)1e6 + 5;
const int MOD = 1479807529;
const int p = 30841;
 
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0); 
    int q;
    cin >> q;
    while (q--) {
      string s;
      cin >> s;
      vector <int> pref((int)s.size()), suff((int)s.size());
      pref[0] = s[0];
      for (int i = 1; i < (int)s.size(); ++i) {
        pref[i] = ((pref[i - 1] * p) % MOD + s[i]) % MOD;
      }
      reverse(s.begin(), s.end());
      suff[0] = s[0];
      for (int i = 1; i < (int)s.size(); ++i) {
        suff[i] = ((suff[i - 1] * p) % MOD + s[i]) % MOD;
      }
      reverse(s.begin(), s.end());
      auto pw = [&] (int a, int n) {
        int res = 1;
        while (n) {
          if (n & 1) {
            res = (res * a) % MOD;
          }
          a = (a * a) % MOD;
          n >>= 1;
        }
        return res;
      };
      auto get_pref = [&] (int l, int r) {
        if (!l) {
          return pref[r];
        }
        return (pref[r] - (pref[l - 1] * pw(p, r - l + 1) % MOD) + MOD) % MOD;
      };
      auto get_suff = [&] (int l, int r) {
        if (!l) {
          return suff[r];
        }
        return (suff[r] - (suff[l - 1] * pw(p, r - l + 1) % MOD) + MOD) % MOD;
      };
      int f1 = -1, s1 = (int)s.size();
      while (s[f1 + 1] == s[s1 - 1] && (s1 - 1) >= (f1 + 1)) {
        ++f1;
        s1--;
      }
      if (f1 == s1) {
        cout << s << '\n';
        continue;
      }
      auto is = [&] (int l, int r) {
        return get_pref(l, r) == get_suff((int)s.size() - r - 1, (int)s.size() - l - 1);
      };
      int mx_pref_p = 0;
      int mx_suff_p = 0;
      for (int i = f1 + 1; i <= s1 - 1; ++i) {
        if (is(f1 + 1, i)) {
          mx_pref_p = max(mx_pref_p, i - (f1 + 1) + 1);
        }
      }
      for (int i = f1 + 1; i <= s1 - 1; ++i) {
        if (is(i, s1 - 1)) {
          mx_suff_p = max(mx_suff_p, (s1 - 1) - i + 1);
        }
      }//cout << f1 << ' ' << s1 << '\n';
      if (mx_pref_p >= mx_suff_p) {
        cout << s.substr(0, f1 + 1);
        cout << s.substr(f1 + 1, mx_pref_p);
        cout << s.substr((int)s.size() - (f1 + 1), (f1 + 1));
        cout << '\n';
      }
      else {
        cout << s.substr(0, f1 + 1);
        cout << s.substr(s1 - mx_suff_p, mx_suff_p);
        cout << s.substr((int)s.size() - (f1 + 1), (f1 + 1));
        cout << '\n';  
      }
    }   
    return 0;
}