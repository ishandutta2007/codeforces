#include <bits/stdc++.h>
using namespace std;
#define sv(x) int sv_##x; cin >> sv_##x; while (sv_##x--)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s = 0;

    sv() {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c > 1)
            s++;
    }

    cout << s;

    return 0;
}