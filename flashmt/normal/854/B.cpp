#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << min(n - k, int(k > 0)) << ' ' << min(n - k, k * 2) << endl;
}