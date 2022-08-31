#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long N, A, B, P, Q;
  cin >> N >> A >> B >> P >> Q;
  cout << N / A * P + N / B * Q - N * __gcd(A, B) / A / B * min(P, Q) << endl;
}