#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  string S;
  cin >> S;

  deque< char > s(S.begin(), S.end());
  while(s.size() && s.front() != '[') s.pop_front();
  while(s.size() && s.back() != ']') s.pop_back();

  if(s.empty()) {
    cout << -1 << endl;
    return 0;
  }
  s.pop_front();
  s.pop_back();

  while(s.size() && s.front() != ':') s.pop_front();
  while(s.size() && s.back() != ':') s.pop_back();

  if(s.size() <= 1) {
    cout << -1 << endl;
    return 0;
  }

  s.pop_front();
  s.pop_back();

  cout << 4 + count(begin(s), end(s), '|') << endl;

}