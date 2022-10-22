#include <iostream>
#include <vector>
#include <set>

using namespace std;

int appear[500];

int main() {

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    
    set<int> S;
    for (int i = 0; i < 22; ++i)
        appear[i] = -1;

    for (int i = 0; i < N; ++i) {
        int current = A[i];
        do {
            S.insert(current);

            int next = current;
            int nextpoz = -1;
            for (int j = 0; j < 22; ++j)
                if (appear[j] != -1 && ((1 << j) & current) == 0) {
                    nextpoz = max(nextpoz, appear[j]);
                }

            if (nextpoz == -1)
                break;

            for (int j = 0; j < 22; ++j)
                if (appear[j] != -1 && appear[j] >= nextpoz )
                    next |= (1 << j);

            current = next;
        } while (1);

        for (int j = 0; j < 22; ++j)
            if ((1 << j) & A[i])
                appear[j] = i;
    }

    cout << S.size();
}