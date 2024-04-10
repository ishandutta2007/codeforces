#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int N, M; cin >> N >> M;

    int S = N + 1;
    long long answer = 0;
    for (int a = M + 1; a <= N - M and a <= (N + 1) / 2; ++a) {
        register int aux = 0;
        for (int b = M + 1; b <= N - M; ++b) {
            int X = 2 * S * a + a * b - S * b - 2 * a * a;
            int Y = a + b;
            int c = X / Y - M - (X % Y == 0);
            if (c > N - 2 * M)
                c = N - 2 * M;
            if (c < 0)
                break;
            aux += c;
        }

        if (N % 2)
            if (a < (N + 1) / 2)
                answer += 2 * aux;
            else
                answer += aux;
        else
            answer += 2 * aux;
    }

    cout << answer * 3 << "\n";
}