#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main()
{
  int64 N;
  cin >> N;
  bool flag = false;
  for(int i = 2; i * i <= N; i++) {
    if(N % i == 0) flag = true;
  }
  if(!flag) {
    cout << 1 << endl;
  } else if(N % 2 == 0) {
    cout << 2 << endl;
  } else {

    flag = false;
    N -= 2;
    for(int i = 2; i * i <= N; i++) {
      if(N % i == 0) flag = true;
    }
    
    if(!flag) cout << 2 << endl;
    else cout << 3 << endl;
  }

}