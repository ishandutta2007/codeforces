// July 20, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  string s;
  cin >> s;
  int n = s.size();
  vector<int> os;
  vector<int> v_cnt;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      os.push_back(i);
      v_cnt.push_back(i - last - 1);
      last = i;
    }
  }
  v_cnt.push_back(n - 1 - last);
  vector<int> psa(v_cnt.size() + 1, 0);
  for (int i = 0; i < v_cnt.size(); i++) {
    psa[i + 1] = psa[i] + (v_cnt[i] >= 2 ? v_cnt[i] - 1 : 0);
  }
  long long ans = 0;
  for (int i = 0; i < os.size(); i++) {
    ans += 1LL * psa[i + 1] * (psa.back() - psa[i + 1]);
  }
  cout << ans << '\n';


  return 0;
}