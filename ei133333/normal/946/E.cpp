#include<bits/stdc++.h>

using namespace std;

typedef long long int64;

string S;
vector< char > st;
bool fail[2001][1 << 10];

bool rec(int idx, bool free, int bit) {
  if(idx == -1) {
    return (__builtin_popcount(bit) == 0);
  }
  if(idx <= 2000 && free && fail[idx][bit]) {
    return (false);
  }
  for(int i = free ? 9 : S[idx] - '0'; i >= 0; i--) {
    if(rec(idx - 1, free | (S[idx] - '0' != i), bit ^ (1 << i))) {
      st.emplace_back(i + '0');
      return (true);
    }
  }
  if(idx <= 2000 && free) fail[idx][bit] = true;
  return (false);
}


int main() {

  int N;
  cin >> N;

  auto is_same = [](const string &s) {
    if(s.back() != '1') return (false);
    for(int i = 0; i + 1 < s.size(); i++) if(s[i] != '0') return (false);
    return (true);
  };

  while(N--) {
    cin >> S;
    for(int i = (int) S.size() - 1; i >= 0; i--) {
      if(S[i] == '0') {
        S[i] = '9';
      } else {
        S[i]--;
        break;
      }
    }
    reverse(begin(S), end(S));
    while(S.back() == '0') S.pop_back();
    if(S.size() % 2 == 1) {
      cout << string(S.size() - 1, '9') << endl;
    } else if(is_same(S)) {
      cout << string(S.size() - 2, '9') << endl;
    } else {
      rec(S.size() - 1, false, 0);
      for(int i = (int) st.size() - 1; i >= 0; i--) cout << st[i];
      cout << endl;
      st.clear();
    }
  }
}