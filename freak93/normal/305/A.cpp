#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;

    int answer = 0;
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        V[i] = x;
        if (x == 0)
            answer |= 1;
        else if (x == 100)
            answer |= 2;
        else if (x > 0 and x < 10)
            answer |= 4;
        else if (x > 0 and x < 100 and x % 10 == 0)
            answer |= 8;
        else
            answer |= 16;
    }

    int x = 0;
    for (int i = 0; i < 4; ++i)
        if ((1 << i) & answer)
            ++x;

    int y = 0;
    if (1 & answer)
        ++y;
    if (2 & answer)
        ++y;
    if (16 & answer)
        ++y;

    if (y > x) {
        x = y;
        answer &= 19;
    } else
        answer &= 15;

    cout << x << "\n";

    for (auto &x: V) {
        if (x == 0 and (answer & 1)) {
            answer ^= 1;
            cout << 0 << " ";
        } else

        if (x == 100 and (answer & 2)) {
            answer ^= 2;
            cout << 100 << " ";
        } else

        if (x > 0 and x < 10 and (answer & 4)) {
            answer ^= 4;
            cout << x << " ";
        } else

        if (x > 0 and x < 100 and x % 10 == 0 and (answer & 8)) {
            answer ^= 8;
            cout << x << " ";
        } else if ((answer & 16)) {
            cout << x << " ";
            answer ^= 16;
        }
    }
}