#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long cmmdc(long long a, long long b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    long long up = 0;
    long long down = 0;

    long long sum = 0;

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    for (int i = 0; i < N; ++i) {
        int x = A[i];
        up += x;
        up += 2LL * i * x - sum;
        sum += 2 * x;
    }

    down = N;

    long long v = cmmdc(up, down);
    up /= v;
    down /= v;
    cout << up << " " << down << "\n";
}