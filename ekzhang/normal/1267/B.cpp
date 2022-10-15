#include <bits/stdc++.h>
using namespace std;
 
typedef pair<char, int> pii;
 
int main(){
  vector<pii> compressed;
  string s; cin >> s;
  char cur = '.';
  int cnt = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == cur){
      ++cnt;
    }
    else{
      if (cnt) compressed.push_back(make_pair(cur, cnt));
      cur = s[i];
      cnt = 1;
    }
  }
  compressed.push_back(make_pair(cur, cnt));
  if (compressed.size() % 2 == 0){
    cout << 0 << endl;
    return 0;
  }
  else{
    int med = (compressed.size() - 1) / 2;
    if (compressed[med].second < 2){
      cout << 0 << endl;
      return 0;
    }
    else{
      for (int i = med - 1; i >= 0; i--){
        if (compressed[i].second + compressed[med + (med - i)].second <= 2 || compressed[i].first != compressed[med + (med - i)].first){
          cout << 0 << endl;
          return 0;
        }
      }
      cout << compressed[med].second + 1 << endl;
      return 0;
    }
  }
}