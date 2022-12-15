#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a;
    if(a == 1) {
        cout << -1 << '\n';
    } else if(a & 1) {
        cout << a-1 << ' ' << 2 << '\n';
    } else {
        cout << a << ' ' << 2 << '\n';
    }
}