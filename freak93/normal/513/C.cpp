#include <iostream>
#include <algorithm>

using namespace std;

int L[5], R[5];

typedef long double double64;

int main() {
    int N; cin >> N;

    for (int i = 0; i < N; ++i)
        cin >> L[i] >> R[i];

    long double answer = 0;
    int maxt = *max_element(R, R + N);
    for (int i = 1; i <= maxt; ++i)
        for (int j = 1; j < (1 << N); ++j) {
            bool good = true;
            long double prob = 1;
            int many = 0;
            for (int k = 0; k < N; ++k) {
                if (((1 << k) & j) && (i < L[k] || i > R[k]))
                    good = false;
                if ((1 << k) & j)
                    prob /= double64(R[k] - L[k] + 1);
                if ((1 << k) & j)
                    ++many;
            }

            if (!good)
                continue;

            if (many > 1)
                many = 1;
            else
                many = 0;
            for (int k = 0; k < N + many; ++k) {
                if ((1 << k) & j)
                    continue;
                if (k != N && R[k] <= i)
                    continue;
                long double partialProb = prob;
                if (k != N)
                    partialProb *= double64(R[k] - max(L[k] - 1, i)) / double64(R[k] - L[k] + 1);
                for (int l = 0; l < N; ++l) {
                    if ((1 << l) & j)
                        continue;
                    if (l == k)
                        continue;
                    if (L[l] >= i)
                        partialProb = 0;
                    else
                        partialProb *= double64(min(R[l] + 1, i) - L[l]) / double64(R[l] - L[l] + 1);
                }
                answer += partialProb * i;
            }
       }

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(12);
    cout << answer << "\n";
}