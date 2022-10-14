// Codeforces Beta Round #1
// Problem A -- Theatre Square
#include <iostream>
#include <cmath>

using namespace std;

long long n, m, a;

int main()
{
  cin >> n >> m >> a;
  cout << (long long)ceil((double)n / a) * (long long)ceil((double)m / a) << "\n";
  return 0;
}