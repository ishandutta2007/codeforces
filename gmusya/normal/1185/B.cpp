#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    string s1, s2;
    cin >> s1 >> s2;
    vector <pair <int, int>> a, b;
    int cnt = 0;
    char c = ' ';
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != c) {
        a.push_back({cnt, c});
        cnt = 0;
        c = s1[i];
      }
      cnt++;
    }
    a.push_back({cnt, c});
    cnt = 0;
    c = ' ';
    for (int i = 0; i < s2.size(); i++) {
      if (s2[i] != c) {
        b.push_back({cnt, c});
        cnt = 0;
        c = s2[i];
      }
      cnt++;
    }
    b.push_back({cnt, c});
    if (a.size() != b.size()) {
      cout << "NO\n";
      continue;
    }
    bool tf = true;
    for (int i = 0; i < a.size(); i++)
      if (a[i].second != b[i].second || a[i].first > b[i].first)
        tf = false;
    if (tf)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}