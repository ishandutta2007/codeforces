#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int main()
{
  int64 N;
  vector< int64 > B;
  cin >> N;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    int64 D;
    cin >> D;
    if(D % 2LL == 1LL) B.push_back(D);
    ret += D;
  }
  if(B.size() % 2 == 1) {
    ret -= *min_element(B.begin(), B.end());
  }
  cout << ret << endl;

}