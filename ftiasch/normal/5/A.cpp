// Codeforces Beta Round #5
// Problem A -- Chat Server's Outgoing Traffic
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int ans = 0, usr = 0; string tmp;
  while(getline(cin, tmp))
    if(tmp[0] == '+')
      usr ++;
    else
    if(tmp[0] == '-')
      usr --;
    else
      ans += usr * (tmp.size() - tmp.find(':') - 1);
  cout << ans << "\n";
  return 0;
}