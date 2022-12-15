#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool contain[200][26];
int sz[200];

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for(char c : s) {
      contain[i][c-'a'] = 1;
    }
    sz[i] = s.size();
  }
  int ans = 0;
  for(int i = 0; i < 26; i++) {
    for(int j = i+1; j < 26; j++) {
      int cur = 0;
      for(int k = 0; k < n; k++) {
        bool valid = true;
        for(int k2 = 0; k2 < 26; k2++) {
          if(k2 != i && k2 != j && contain[k][k2]) valid = false;
        }
        if(valid) cur += sz[k];
      }
      ans = max(cur, ans);
    }
  }
  cout << ans << endl;
}