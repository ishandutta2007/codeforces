#include <iostream>
#include <vector>
#include <array>

using namespace std;

array<int, 31> mex = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

int main() {
    int N; cin >> N;

    int M;
    for (M = 1; M * M <= N; ++M);

    vector<int> used(M);

    array<int, 31> many = {0};

    many[1] += 1;
    for (int i = 2; i < M; ++i)
        if (not used[i]) {
            int now = 0;
            for (int64_t j = i; j <= N; j *= i, ++now)
                if (j < M)
                    used[j] = 1;
            ++many[now];
        }

    int total = N;
    for (int i = 0; i < 31; ++i)
        total -= i * many[i];
    many[1] += total;

    int answer = 0;
    for (int i = 0; i < 31; ++i)
        if (many[i] % 2)
            answer ^= mex[i];

    if (answer)
        cout << "Vasya\n";
    else
        cout << "Petya\n";
}