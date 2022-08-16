#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  string s;
  int ret = 0;
  while(cin >> s) {
    int beet = 0;
    for(auto &c : s) beet += isupper(c);
    ret = max(ret, beet);
  }
  cout << ret << endl;
}