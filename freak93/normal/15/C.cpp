#include <iostream>

using namespace std;

int parity(long long N, long long bit) {
    long long many = 0;
    if (N & bit)
        many += (N & (bit - 1)) + 1;

    N /= bit;
    if (N & 1)
        --N;
    N /= 2;

    many += N * bit;

    //cerr << "From 1 to " << N << " we have the bit " << bit << " " << many << " times\n";
    return many % 2;
}

int main() {
    int N; cin >> N;

    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        long long from, to;
        cin >> from >> to;
        to += from;

        for (long long bit = 1; bit < to; bit *= 2) {
            answer ^= bit * parity(to - 1, bit);
            answer ^= bit * parity(from - 1, bit);
        }
        cerr << answer << "\n";
    }

    if (answer)
        cout << "tolik";
    else
        cout << "bolik";
}