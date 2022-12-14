#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    int m = max(int(s.size()) - 2, 0);
    int n = stoi(s.substr(m)) % 4;
    cout << llround(1 + pow(2, n) + pow(3, n) + pow(4, n)) % 5;
}