#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 Read()
{
  int64 b, X;
  cin >> b >> X;
  vector< int > d(b);
  for(int i = 0; i < b; i++) {
    cin >> d[i];
  }
  int64 A = 0, B = 1;
  for(int i = b - 1; i >= 0; i--) {
    A += d[i] * B;
    B *= X;
  }
  return(A);
}

int main()
{
  int64 A = Read(), B = Read();
  if(A < B) puts("<");
  else if(A == B) puts("=");
  else puts(">");


}