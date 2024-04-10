#include<iostream>

using namespace std;

int main() {
    long long N;
    long long K; cin >> N >> K;
    //.if (K<N/2)
    long long numOdd = N - N / 2;
    if (K<=numOdd)
    cout << 2 * K - 1 << '\n';
    if (K>numOdd)
    cout << (K - numOdd) * 2 << '\n'; //have you heard of else?
    return 0;
}