#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  string good, s;
  bool beet[26] = {};
  int N;

  cin >> good;
  for(auto &c : good) beet[c - 'a'] = true;
  cin >> s;
  cin >> N;

  auto appear = s.find('*');
  if(appear == string::npos) {

    while(N--) {
      string t;
      cin >> t;
      if([&]()
      {
        if(s.size() != t.size()) return (false);
        for(int i = 0; i < s.size(); i++) {
          if(s[i] == t[i]) continue;
          if(s[i] == '?' && beet[t[i] - 'a']) continue;
          return (false);
        }
        return (true);
      }())
        cout << "YES" << endl;
      else cout << "NO" << endl;
    }

  } else {
    string latte = s.substr(0, appear);
    string malta = s.substr(appear + 1);

    while(N--) {
      string t;
      cin >> t;
      if([&]()
      {
        if(latte.size() + malta.size() > t.size()) return (false);
        for(int i = 0; i < latte.size(); i++) {
          if(latte[i] == t[i]) continue;
          if(latte[i] == '?' && beet[t[i] - 'a']) continue;
          return (false);
        }
        int ptr = t.size() - 1;
        for(int i = (int) malta.size() - 1; i >= 0; i--, --ptr) {
          if(malta[i] == t[ptr]) continue;
          if(malta[i] == '?' && beet[t[ptr] - 'a']) continue;
          return (false);
        }
        int rest = t.size() - latte.size() - malta.size();
        for(int i = 0; i < rest; i++) {
          if(!beet[t[latte.size() + i] - 'a']) continue;
          return (false);
        }
        return (true);
      }())
        cout << "YES" << endl;
      else cout << "NO" << endl;
    }

  }
}