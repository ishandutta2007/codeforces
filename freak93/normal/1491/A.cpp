#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }

    for (int i = 0; i < Q; ++i) {
        int type, x; cin >> type >> x;

        if (type == 1) {
            --x;
            sum += 1 - 2 * A[x];
            A[x] = 1 - A[x];
        } else {
            if (x <= sum)
                cout << "1\n";
            else 
                cout << "0\n";
        }
    }
}