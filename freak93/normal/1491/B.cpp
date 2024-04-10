#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T; cin >> T;

    while (T--) {
        int N, U, V; cin >> N >> U >> V;

        vector<int> A(N);
        for (int i = 0; i < N; ++i)
            cin >> A[i];

        int dist = 0;
        for (int i = 1; i < N; ++i)
            dist = max(dist, max(A[i] - A[i - 1], A[i - 1] - A[i]));

        if (dist >= 2)
            cout << 0 << "\n";
        else if (dist == 1)
            cout << min(U, V) << "\n";
        else 
            cout << V + min(U, V) << "\n";
    }
}