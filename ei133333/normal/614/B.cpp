#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int N;
  cin >> N;
  string S = "";
  bool zero = false;
  bool only = true;
  for(int i = 0; i < N; i++) {
    string K;
    cin >> K;
    if(K == "0") zero = true;
    else if(K[0] == '1' && K.substr(1) == string(K.size() - 1, '0')) S += string(K.size() - 1, '0');
    else S = K + S, only = false;;
  }
  if(zero) cout << 0 << endl;
  else if(only) cout << "1" << S << endl;
  else cout << S << endl;
}