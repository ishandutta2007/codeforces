#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;

  bool first = false;
  for(int i = 20; i >= 0; i--) {
    if((N >> i) & 1) {
      if(first++) cout << " ";
      cout << i + 1;
    }
  }
  cout << endl;

}