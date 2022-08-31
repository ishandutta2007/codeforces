#include <bits/stdc++.h>

using namespace std;

int main()
{
  int S, V1, V2, T1, T2;
  cin >> S >> V1 >> V2 >> T1 >> T2;

  int latte = S * V1 + T1 + T1;
  int malta = S * V2 + T2 + T2;
  if(latte < malta) cout << "First" << endl;
  else if(latte == malta) cout << "Friendship" << endl;
  else cout << "Second" << endl;

}