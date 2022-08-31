#include<bits/stdc++.h>
using namespace std;
typedef long long int64;


int main()
{
  int64 N, fieldA[10000] = {}, fieldB[10000] = {};

  cin >> N;
  for(int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    fieldA[A - B + 5000]++;
    fieldB[A + B + 5000]++;
  }
  int64 ret = 0;
  for(int i = 0; i < 10000; i++) {
    ret += 1LL * fieldA[i] * (fieldA[i] - 1) / 2LL;
    ret += 1LL * fieldB[i] * (fieldB[i] - 1) / 2LL;
  }
  cout << ret << endl;
}