#include <iostream>
#include <vector>

using namespace std;

int main () {
  long long n;
  cin >> n;
  vector <long long> a(n);
  for (long long i = 0; i < n; i++)
    cin >> a[i];
  if (n == 1) {
    cout << "1 1\n" << -a[0] << "\n1 1\n0\n1 1\n0";
    return 0;
  }
  vector <long long> r(n);
  for (long long i = 0; i < n; i++)
    r[i] = (a[i] % n + n) % n;
  cout << "1 " << n - 1 << '\n';
  for (long long i = 0; i + 1 < n; i++) {
    cout << r[i] * (n - 1) << ' ';
    a[i] += r[i] * (n - 1);
  }
  cout << '\n';
  cout << n << ' ' << n << '\n' << -a[n - 1] << '\n' << "1 " << n << '\n';
  a[n - 1] = 0;
  for (long long i = 0; i < n; i++)
    cout << -a[i] << ' ';
  return 0;
}