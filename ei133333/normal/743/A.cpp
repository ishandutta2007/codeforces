#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N, A, B;
  string S;

  cin >> N >> A >> B;
  --A, --B;
  cin >> S;
  cout << (int) (S[A] != S[B]) << endl;
}