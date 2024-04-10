#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    int X;
    cin >> S >> X;
    if (S == "ABC") cout << (X < 2000 ? "YES\n" : "NO\n");
    else if (S == "ARC") cout << (X < 2800 ? "YES\n" : "NO\n");
    else cout << (X >= 1200 ? "YES\n" : "NO\n");
    return 0;
}