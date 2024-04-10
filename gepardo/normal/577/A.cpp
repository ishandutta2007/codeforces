#include <iostream>
#include <vector>

using namespace std;

int n, x;

int main()
{
    cin >> n >> x;
    int res = 0;
    for (int i = 1; i <= n; i++) if (x % i == 0 && x / i <= n) res++;
    cout << res;
}