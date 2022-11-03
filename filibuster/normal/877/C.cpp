#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

int main() {
    int n;
    cin >> n;

    cout << n + n / 2 << endl;

    for(int i = 2; i <= n; i += 2)
        cout << i << ' ';
    for(int i = 1; i <= n; i += 2)
        cout << i << ' ';
    for(int i = 2; i <= n; i += 2)
        cout << i << ' ';
}