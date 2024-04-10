#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> C(n);
        LL sum = 0;
        for (int& Ci : C) {
            cin >> Ci;
            sum += Ci;
        }
        vector<int> A(n), B(n);
        for (int i = n - 1, s = 0, k = sum / n; i >= 0; i -= 1) {
            s += B[i];
            A[i] = C[i] + s == (i + 1);
            if (k) s -= 1;
            if (i >= k) B[i - k] += 1;
            k -= A[i];
        }
        for (int Ai : A) cout << Ai << " ";
        cout << "\n";
    }
}