#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;

  int type[26];
  memset(type, -1, sizeof(type));
  int ret = 0;

  for(int i = 0; i < N-1; i++) {
    string t, x;
    cin >> t >> x;

    bool which[26];
    int beet = 0;
    for(int j = 0; j < 26; j++) {
      which[j] = count(begin(x), end(x), (char) (j + 'a')) > 0;
      if(type[j] == -1) ++beet;
    }

    if(t == "!") {
      if(beet <= 1) ++ret;
      for(int j = 0; j < 26; j++) {
        if(!which[j]) type[j] = 0;
      }
    } else if(t == ".") {
      for(int j = 0; j < 26; j++) {
        if(which[j]) type[j] = 0;
      }
    } else {
      if(beet <= 1) ++ret;
      for(int j = 0; j < 26; j++) {
        if(which[j]) type[j] = 0;
      }
    }
  }

  cout << ret << endl;

}