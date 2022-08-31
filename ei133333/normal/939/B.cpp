#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main()
{
  int64 N, K;
  cin >> N >> K;

  int64 ret = -1;
  int64 idx, box;


  for(int i = 0; i <K; i++) {
    int64 A;
    cin >> A;

    int64 sz = N / A * A;
    if(ret < sz) {
      ret = sz;
      idx = i + 1;
      box = N / A;
    }
  }
  cout << idx << " " << box << endl;
}