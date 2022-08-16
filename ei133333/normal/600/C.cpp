#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string s;
  cin >> s;
  int v[26] = {};
  for(auto &c : s) v[c - 'a']++;

  deque< int > odd;
  for(int i = 0; i < 26; i++) {
    if(v[i] % 2 == 1) odd.emplace_back(i);
  }
  while(odd.size() >= 2) {
    int p = odd.front();
    int q = odd.back();
    odd.pop_front();
    odd.pop_back();
    v[p]++;
    v[q]--;
  }

  string pre;
  for(int i = 0; i < 26; i++) {
    int t = v[i] / 2;
    while(t--) pre += (char) (i + 'a');
  }
  cout << pre;
  if(odd.size())cout << (char) ('a' + odd[0]);
  reverse(begin(pre), end(pre));
  cout << pre << endl;
}