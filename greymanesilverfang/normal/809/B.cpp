#include <iostream>
#include <stdio.h>
using namespace std;

string reply;

int Solve(int L, int R) {
    if (L >= R)
        return (L == 1 ? L : R);
    int i = (L + R) / 2 - (L + R + 1) % 2;
    int j = (L + R) / 2 + 1;
    cout << 1 << ' ' << i << ' ' << j << '\n';
    fflush(stdout);
    cin >> reply;
    return (reply == "TAK" ? Solve(L, j - 1) : Solve(i + 1, R));
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int x = Solve(1, n);
    if (x > 1 && x < n) {
        int y = Solve(1, x - 1);
        int z = Solve(x + 1, n);
        cout << 1 << ' ' << y << ' ' << z << '\n';
        fflush(stdout);
        cin >> reply;
        cout << 2 << ' ' << x << ' ' << (reply == "TAK" ? y : z);
    } else if (x == 1)
        cout << 2 << ' ' << x << ' ' << Solve(2, n);
    else if (x == n)
        cout << 2 << ' ' << x << ' ' << Solve(1, n - 1);
    return 0;
}