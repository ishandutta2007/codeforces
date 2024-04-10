#include <iostream>

using namespace std;

int cmmdc(int A, int B) {
    if (B == 0)
        return A;
    return cmmdc(B, A % B);
}

int abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

pair<int, int> best(int X, int A, int N) {
    if (X - (A + 1) / 2 >= 0 and X + A / 2 <= N)
        return {X - (A + 1) / 2, X + A / 2};
    if (X - A / 2 >= 0 and X + (A + 1) / 2 <= N)
        return {X - A / 2, X + (A + 1) / 2};
    if (abs(2 * X - 0 - A) < abs(2 * X - N - (N - A)))
        return {0, A};
    return {N - A, N};
}

int main() {
    int N, M, X, Y, A, B; cin >> N >> M >> X >> Y >> A >> B;

    int C = cmmdc(A, B);
    A /= C;
    B /= C;

    C = min(N / A, M / B);
    A *= C;
    B *= C;

    auto x12 = best(X, A, N);
    auto y12 = best(Y, B, M);
    cout << x12.first << " " << y12.first << " " << x12.second << " " << y12.second << "\n";
}