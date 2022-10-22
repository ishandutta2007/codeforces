#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int ask(int number) {
    cout << "? " << number << endl;
    int x; cin >> x;
    return x;
}


bool in_range(int x, int start, int end) {
    if (start > end)
        swap(start, end);
    return x >= start && x <= end;
}

int sign(int x) {
    if (x < 0)
        return -1;
    if (x > 0)
        return 1;
    return 0;
}

int main() {
    int N; cin >> N;

    if (N == 2) {
        cout << "! -1" << endl;
        return 0;
    }

    int x = ask(1);
    int y = ask(N / 2 + 1);

    if (x == y) {
        cout << "! 1" << endl;
        return 0;
    }

    if ((max(x, y) - min(x, y)) % 2) {
        cout << "! -1" << endl;
        return 0;
    }

    int begin = 1;
    int end = N / 2 + 1;

    int sign_begin = sign(x - y);
    int sign_end = sign(y - x);

    assert(sign_begin != sign_end);
    while (begin < end) {
        int mid = (begin + end) / 2;
        int z = ask(mid);
        int t = ask(mid + N / 2);

        int sign_mid = sign(z - t);
        if (sign_mid == 0) {
            cout << "! " << mid << endl;
            return 0;
        }

        if (sign_mid == sign_begin) {
            begin = mid;
        } else {
            end = mid;
        }
    }

    assert(false);
}