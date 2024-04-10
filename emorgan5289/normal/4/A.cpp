#include <bits/stdc++.h>
using namespace std;

int a[63000000 / 4];

int main() {
    int w; cin >> w;
    cout << (w%2 == 0 && w > 2 ? "YES" : "NO") << "\n";
}