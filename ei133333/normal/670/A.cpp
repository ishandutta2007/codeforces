#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;
  cout << N / 7 * 2 + (N % 7 >= 6) << " " << N / 7 * 2 + min(N % 7, 2) << endl;
}