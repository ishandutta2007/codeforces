#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int s = -1;
    int last = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        s += x + (x & !last);
        last = x;
    }
    cout << max(s, 0) << '\n';
}