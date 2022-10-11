#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll i, j;

ll n, q, Q, T, m, k, r, x;
ll a, b, c, d;
string s, t, p;
int cnt[26];

int main() {
  io;
  cin >> Q;
  f0r(q, Q) {
    cin >> s >> t >> p;
    ms(cnt, 0);
    f0r(i, p.length()) {
      cnt[p[i] - 'a']++;
    }
    int siz = s.length(), tl = t.length();
    int spt = 0, tpt = 0;
    bool f = 1;
    while (spt < s.length() && tpt < tl) {
      if (s[spt] == t[tpt]) { //ok
        spt++;
        tpt++; 
      } else { //put letter
        cnt[t[tpt] - 'a']--;
        if (cnt[t[tpt] - 'a'] < 0) {
          f = 0;
          break;
        }
        tpt++;
        siz++;
      }
      if (spt == s.length()) {
        while (tpt < tl) {
          cnt[t[tpt] - 'a']--;
          if (cnt[t[tpt] - 'a'] < 0) {
            f = 0;
            break;
          }
          tpt++;
          siz++;
        }
      }
    }
    if (siz != tl) {
      f = 0;
    }
    cout << (f ? "YES" : "NO") << endl;
  }
}