#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int s = a + b + c;

    int x = s / 9;

    if(x * 9 != s || x > a || x > b || x > c) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}