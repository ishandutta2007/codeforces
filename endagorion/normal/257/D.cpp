#include <vector>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int s = 0;
    vector<bool> plus(N);
    for (int i = N - 1; i >= 0; --i) {
        plus[i] = s >= 0;
        s -= (plus[i] ? 1 : -1) * a[i];
    }
    for (int i = 0; i < N; ++i) {
        cout << ((s >= 0) != plus[i] ? '+' : '-');
    }
    cout << '\n';
    return 0;
}