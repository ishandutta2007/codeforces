#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

static const int kBits = 24;

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;

    vector<int> B(N);
    for (int i = 0; i < N; ++i)
        cin >> B[i];

    if (N == 2) {
        if (B[0] == B[1]) {
            cout << "YES\n";
            cout << "0 " << B[0] << "\n";
            return 0;
        }
        cout << "NO\n";
        return 0;
    }

    // maybe 2 are identical
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (B[i] == B[j]) {
                B[i] = 0;
                cout << "YES\n";
                for (auto &x : B)
                    cout << x << " ";
                cout << "\n";
                return 0;
            }

    sort(B.begin(), B.end(), [&](int x, int y) {
        return x % 2 < y % 2;
    });

    do {
        if ((B[0] + B[1] + B[2]) % 2)
            continue;
        int sum = B[0] + B[1] + B[2];
        sum /= 2;
        vector<int> A(N);
        A[0] = sum - B[0];
        A[1] = sum - B[1];
        A[2] = sum - B[2];
        for (int i = 3; i < N; ++i)
            A[i] = B[i] - A[0];
        cout << "YES\n";
        for (auto &x : A)
            cout << x << " ";
        cout << "\n";
        return 0;
    } while (next_permutation(B.begin(), B.begin() + min(N, 6)));

    gp_hash_table<int, int> M[kBits];
    int x = -1, y = -1;
    for (int mask = 1; ; ++mask) {
        if (N < kBits && mask >= (1 << N))
            break;
        int sum = 0;
        int bits = 0;
        for (int i = 0; (1 << i) <= mask; ++i)
            if ((1 << i) & mask) {
                sum += B[i];
                ++bits;
            }
        if (bits > kBits / 2)
            continue;
        if (M[bits][sum]) {
            x = M[bits][sum];
            y = mask;
            break;
        } else {
            M[bits][sum] = mask;
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    int common = (x & y);
    x -= common;
    y -= common;

    vector<int> left, right;
    for (int i = 0; i < kBits; ++i) {
        if ((1 << i) & x)
            left.push_back(i);
        if ((1 << i) & y)
            right.push_back(i);
    }

    vector<int> A(left.size() * 2);
    A[0] = 0;
    A[1] = B[left[0]];
    for (int i = 1; i < int(left.size()); ++i) {
        A[2 * i] = B[right[i]] - A[2 * i - 1];
        A[2 * i + 1] = B[left[i]] - A[2 * i];
    }

    for (int i = 0; i < N; ++i)
        if (i >= kBits || ((1 << i) & (x | y)) == 0)
            A.push_back(B[i]);

    cout << "YES\n";
    for (auto &x : A)
        cout << x << " ";
    cout << "\n";
}