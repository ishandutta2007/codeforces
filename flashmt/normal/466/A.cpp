#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int m, n, a, b;
    cin >> n >> m >> a >> b;
    cout << min(min(a * n, b * (n / m + 1)), b * (n / m) + a * (n % m)) << endl;
}