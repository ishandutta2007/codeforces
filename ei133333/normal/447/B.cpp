#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int main(){
  string s;
  int k, w[26];
  int64 value = 0LL;

  cin >> s;
  cin >> k;
  for(int i = 0; i < 26; i++){
    cin >> w[i];
  }
  for(int i = 0; i < s.size(); i++){
    value += (i + 1) * w[s[i] - 'a'];
  }
  int hoge = *max_element( w, w + 26) ;
  for(int i = 0; i < k; i++){
    value += (i + 1 + s.size()) * hoge;
  }
  cout << value << endl;
}