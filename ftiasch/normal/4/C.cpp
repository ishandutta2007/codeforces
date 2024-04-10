// Codeforces Beta Round #4
// Problem C -- Registration system
#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> data;

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  data.clear();
  for(int i = 0; i < n; ++ i)
  {
    string temp;
    cin >> temp;
    if(data.find(temp) == data.end())
      cout << "OK\n";
    else
      cout << temp << data[temp] << "\n";
    data[temp] ++;
  }
  return 0;
}