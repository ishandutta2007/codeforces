#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;


const int N = 200200;
unsigned l[N], r[N], v[N];
unsigned bigl[N], bigr[N], smalll[N], smallr[N];
unsigned least[1 << 16];
unsigned most[1 << 16];
int x[(1 << 16) + 5];
int y[(1 << 16) + 5];
int askx[(1 << 16) + 5];
int asky[(1 << 16) + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, q;
    cin >> k >> q;
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i] >> v[i];
        bigl[i] = l[i] >> k;
        smalll[i] = l[i] & ((1 << k) - 1);
        bigr[i] = r[i] >> k;
        smallr[i] = r[i] & ((1 << k) - 1);
    }
    for (int bit = 0; bit < 16; ++bit) {
        fill_n(x, 1 << k, 0);
        fill_n(y, 1 << k, 0);
        fill_n(askx, 1 << k, 0);
        fill_n(asky, 1 << k, 0);
        for (int i = 0; i < q; ++i) {
            if ((v[i] >> bit) & 1) {
                ++y[bigl[i]];
                --y[bigr[i] + 1];
                if (bigr[i] - bigl[i] >= 2) {
                    ++x[0];
                    --x[1 << k];
                } else if (bigr[i] - bigl[i] == 1) {
                    ++x[0];
                    --x[smallr[i] + 1];
                    ++x[smalll[i]];
                    --x[1 << k];
                } else {
                    ++x[smalll[i]];
                    --x[smallr[i] + 1];
                }
            }
        }
        bool there_are_ones_in_x = false;
        for (int i = 1; i < (1 << k); ++i) {
            x[i] += x[i - 1];
            y[i] += y[i - 1];
        }
        int real_bit = (1 << bit);
        for (int i = 0; i < (1 << k); ++i) {
            if (x[i] >= 1) {
                least[i] ^= real_bit;
                there_are_ones_in_x = true;
            }
            if (y[i] >= 1) {
                most[i] ^= real_bit;
            }
        }
        for (int i = 0; i < q; ++i) {
            if (!((v[i] >> bit) & 1)) {
                if (bigr[i] - bigl[i] >= 2) {
                    if (y[bigr[i]] >= 1) {
                        ++askx[0];
                        --askx[smallr[i] + 1];
                    }
                    if (y[bigl[i]] >= 1) {
                        ++askx[smalll[i]];
                        --askx[1 << k];
                    }
                    if (there_are_ones_in_x) {
                        ++asky[bigl[i] + 1];
                        --asky[bigr[i]];
                    }
                } else if (bigr[i] - bigl[i] == 1) {
                    if (y[bigr[i]] >= 1) {
                        ++askx[0];
                        --askx[smallr[i] + 1];
                    }
                    if (y[bigl[i]] >= 1) {
                        ++askx[smalll[i]];
                        --askx[1 << k];
                    }
                } else {
                    if (y[bigl[i]] >= 1) {
                        ++askx[smalll[i]];
                        --askx[smallr[i] + 1];
                    }
                }
            }
        }
        for (int i = 0; i < (1 << k); ++i) {
            if (i) {
                askx[i] += askx[i - 1];
                asky[i] += asky[i - 1];
            }
            if (askx[i] >= 1 && x[i] >= 1) {
                cout << "impossible\n";
                return 0;
            }
            if (asky[i] >= 1 && y[i] >= 1) {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    cout << "possible\n";
    for (int i = 0; i < (1 << k); ++i) {
        cout << least[i] << "\n";
    }
    for (int i = 0; i < (1 << k); ++i) {
        cout << most[i] << "\n";
    }



}