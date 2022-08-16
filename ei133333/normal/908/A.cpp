#include<bits/stdc++.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  const string temp = "aeiou13579";
  int ret = 0;
  for(auto &c : S) {
    if(temp.find(c) != string::npos) ++ret;
  }
  cout << ret << endl;
}