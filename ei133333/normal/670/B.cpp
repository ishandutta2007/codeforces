#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N, K, id[100001];

  cin >> N >> K;
  
  int64 pos = 0;
  for(int i = 1; i <= N; i++) {
    cin >> id[i];
    pos += i;
    if(pos >= K) {
      cout << id[i - (pos - K)] << endl;
      break;
    }
  }
}