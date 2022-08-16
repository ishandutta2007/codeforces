#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;

  int ret = 0;
  ret = max( ret, a + b + c);
  ret = max( ret, a + b * c);
  ret = max( ret, a * b + c);
  ret = max( ret, (a + b) * c);
  ret = max( ret, a * (b + c));
  ret = max( ret, a * b * c);

  cout << ret << endl;
}