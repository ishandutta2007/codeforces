#include <bits/stdc++.h>
using namespace std;
int x, bz[2000], flag, cnt, nx;
bool jud(int x) {
    if (x == 2)
        return 1;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main() {
    cin >> x;
    flag = jud(x);
    for (int i = x + 1; i <= 1010; i++) {
        if (i % 2 == 1 && jud(i) == 1) {
            nx = i;
            break;
        }
    }
    if (!flag)
        cout << nx << endl;
    else
        cout << x << endl;
    for (int i = 1; i <= x - 1; i++) printf("%d %d\n", i, i + 1);
    cout << x << " "
         << "1" << endl;
    cnt = nx - x;
    if (flag == 0) {
        for (int i = 1; i <= x; i++) {
            if (cnt == 0)
                break;
            if (bz[i] == 0 && bz[i + 2] == 0) {
                printf("%d %d\n", i, i + 2);
                bz[i] = 1, bz[i + 2] = 1;
                cnt--;
            }
        }
    }
    return 0;
}