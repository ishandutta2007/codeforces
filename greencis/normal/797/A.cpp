#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0)
            v.push_back(i), n /= i;
    }
    if (n > 1)
        v.push_back(n);
    if (v.size() < k)
        cout << -1;
    else {
        for (int i = 0; i < k - 1; ++i) {
            cout << v.back() << " ";
            v.pop_back();
        }
        n = 1;
        while (v.size())
            n *= v.back(), v.pop_back();
        cout << n;
    }
    return 0;
}