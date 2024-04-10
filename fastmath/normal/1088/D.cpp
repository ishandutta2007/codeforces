#include <bits/stdc++.h>

using namespace std;

#define int long long

int get(int c, int d) {
    cout << "? " << c << ' ' << d << '\n';
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}   

const int LG = 30;

signed main() {
    int a = 0, b = 0;
    bool abb = (get(0, 0) == 1);
    for (int i = LG - 1; i >= 0; --i) {
        int x = 1 << i;
        if (abb) {
            int t = get(a + x, b + x);
            if (t == 1) {
                if (get(a + x, b) == 1) {
                    continue;
                }
                else {
                    a += x;
                    b += x;
                }
            }   
            else {
                a += x;
                abb = (get(a, b) == 1);
            }   
        }
        else {
            int t = get(a + x, b + x);
            if (t != 1) {
                if (get(a + x, b) == 1) {
                    continue;
                }
                else {
                    a += x;
                    b += x;
                }   
            }
            else {
                b += x;
                abb = (get(a, b) == 1);
            }   
        }
    }   

    cout << "! " << a << ' ' << b << '\n';
    return 0;
}