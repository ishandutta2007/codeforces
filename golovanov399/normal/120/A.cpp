#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  string s;
  int a;
  cin >> s >> a;
  
  --a;
  
  int b = (s != "front");
  
  if (a == b) {
    cout << "L\n";
  }
  else {
    cout << "R\n";
  }
  
  return 0;
}