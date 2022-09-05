#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int n, K;
bool chk[1024];

int main() {
    cin >> n >> K;

    auto ask = [&](int x) {
        if (!chk[x]) return true;
        cout << "? " << x + 1 << endl;
        string s; cin >> s;
        return s == "N";
    };
    auto reset = [&]() {
        cout << "R" << endl;
    };
    auto print = [&]() {
        cout << "! " << accumulate(chk, chk + n, 0) << endl, exit(0);
    };

    fill(chk, chk + n, 1);
    if (K == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                reset(), ask(i), chk[j] &= ask(j);
            }
        }
        print();
    }
    for (int i = 0; i < n; i++) {
        chk[i] &= ask(i);
    }
    for (int i = 0; i < n; i += K) {
        for (int j = i + K; j < n; j += K) {
            reset();
            for (int k = j; k < j + K / 2; k++) ask(k);
            for (int k = i; k < i + K / 2; k++) chk[k] &= ask(k);
            for (int k = j + K / 2; k < j + K; k++) chk[k] &= ask(k);
            reset();
            for (int k = j + K / 2; k < j + K; k++) ask(k);
            for (int k = i + K / 2; k < i + K; k++) chk[k] &= ask(k);
            for (int k = j; k < j + K / 2; k++) chk[k] &= ask(k);
        }
    }
    print();
    return 0;
}