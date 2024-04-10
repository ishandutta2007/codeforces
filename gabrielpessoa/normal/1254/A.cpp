#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f3f3f3f3f;
const int ms = 105;

char arr[100];
int need[100];
string s[ms];

main() {
  cin.tie(0); ios::sync_with_stdio(0);
  for(int i = 0; i < 26; i++) {
    arr[i] = i + 'a';
    arr[i+26] = i + 'A';
  }
  for(int i = 0; i < 10; i++) {
    arr[i+52] = i+ '0';
  }
  int T;
  cin >> T;
  while(T--) {
    int r, c, k;
    cin >> r >> c >> k;
    int qnt = 0;
    for(int i = 0; i < r; i++) {
      cin >> s[i];
      for(char c : s[i]) {
        if(c == 'R') qnt++;
      }
      if(i & 1) reverse(s[i].begin(), s[i].end());
    }
    for(int i = 0; i < k; i++) {
      need[i] = qnt/k;
      if(qnt % k > i) need[i]++;
    }
    int cur = 0;
    int qntCur = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(s[i][j] == 'R' && qntCur == need[cur]) {
          cur++;
          qntCur = 0;
        }
        qntCur += s[i][j] == 'R';
        s[i][j] = arr[cur];
      }
    }
    for(int i = 0; i < r; i++) {
      if(i & 1) reverse(s[i].begin(), s[i].end());
      cout << s[i] << '\n';
    }
  }
}