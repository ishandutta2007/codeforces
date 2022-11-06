#include <bits/stdc++.h>
using namespace std;

#define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


string s;
vector<int> v[4];
int perm[24][4];
int dic[300];
int n;
int myPerm[4];
int cnt[ms][4];
vector<char> iDic = {'A', 'N', 'O', 'T'};

int get(int idx) {
  int cur = 0, ans = 0;
  for(int i = 0; i < 4; i++) {
    for(int x : v[perm[idx][i]]) {
      for(int j = i+1; j < 4; j++) {
        int pj = perm[idx][j];
        ans += cnt[x][pj];
      }
      for(int j = 0; j < i; j++) {
        int pj = perm[idx][j];
        ans += cnt[n-1][pj] - cnt[x][pj];
      }
      // if(x > cur) ans += x - cur;
      cur++;
    }
  }
  // cout << ans << endl;
  return ans;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    dic['A'] = 0;
    dic['N'] = 1;
    dic['O'] = 2;
    dic['T'] = 3;
    myPerm[0] = 0;
    myPerm[1] = 1;
    myPerm[2] = 2;
    myPerm[3] = 3;
    int curPerm = 0;
    do {
      for(int j = 0; j < 4; j++) perm[curPerm][j] = myPerm[j];
      curPerm++;
    } while(next_permutation(myPerm, myPerm+4));

    // for(int i = 0; i < 24; i++) {
    //   cout << i << ": ";
    //   for(int j = 0; j < 4; j++)
    //   cout << perm[i][j] << ' ';
    //   cout << endl;
    // }
    while(t--) {
      cin >> s;
      for(int i = 0; i < 4; i++) {
        v[i].clear();
      }
      n = s.size();
      for(int i = 0; i < n; i++) {
        char c = s[i];
        int p = dic[s[i]];
        for(int j = 0; j < 4; j++) {
          cnt[i][j] = p == j;
          if(i > 0) cnt[i][j] += cnt[i-1][j];
        }
        v[p].emplace_back(i);
      }
      pair<int, int> ans = {0, 0};
      for(int i = 0; i < 24; i++) {
        ans = max(ans, ii(get(i), -i));
      }
      int idx = -ans.second;
      string res = "";
      for(int i = 0; i < 4; i++) {
        for(int x : v[perm[idx][i]]) res.push_back(iDic[perm[idx][i]]);
      }
      cout << res << '\n';
      // cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}