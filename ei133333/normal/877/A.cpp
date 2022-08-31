#include<bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;

  int ret = 0;
  for(auto &T : {"Danil", "Olya", "Slava", "Ann", "Nikita"}) {
    for(int i = 0; i < S.size(); i++) {
      if(S.substr(i).find(T) == 0) ++ret;
    }
  }

  if(ret != 1) cout << "NO" << endl;
  else cout << "YES" << endl;
}