#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int i = 0;
    while (a <= b)
        a *= 3, b *= 2, i++;
    
    cout << i;

    return 0;
}