#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 0;
    for (;;) {
        int a;
        cin >> a;
        if (a == 1)
            break;
        i++;
    }

    cout << abs(i % 5 - 2) + abs(i / 5 - 2);

    return 0;
}