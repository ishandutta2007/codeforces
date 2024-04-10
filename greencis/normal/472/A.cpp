#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
 if (n <= 1) return false;
 for (int i = 2; i * i <= n; ++i)
  if (n % i == 0) return false;
 return true;
}

int main()
{
 int n;
 cin >> n;
 for (int i = 4; ; ++i) {
  if (!isprime(i) && !isprime(n-i)) {
   cout << i << " " << n-i;
   return 0;
  }
 }
 return 0;
}