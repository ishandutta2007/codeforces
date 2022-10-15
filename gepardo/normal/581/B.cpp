#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) b[i] = max(b[i + 1], a[i]);
    c[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) if (b[i + 1] < a[i]) c[i] = 0; else c[i] = b[i + 1] - a[i] + 1;
    for (int i = 0; i < n; i++) cout << c[i] << " ";
}