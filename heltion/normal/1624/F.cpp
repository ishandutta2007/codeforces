#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int L = 1, R = n - 1;
    while (L < R) {
        int M = (L + R + 1) / 2;
        int c = n - M % n, k = M / n + 1;
        cout << "+ " << c << endl;
        int d;
        cin >> d;
        if (d >= k) L = M;
        else R = M - 1;
        L += c;
        R += c;
    }
    cout << "! " << L << "\n";
}