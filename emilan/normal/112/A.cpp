#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    transform(begin(a), end(a), begin(a), ::tolower);
    transform(begin(b), end(b), begin(b), ::tolower);

    cout << a.compare(b);

    return 0;
}