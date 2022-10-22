#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> stack;
    for (int i = 0; i < N; ++i) {
        int where = lower_bound(stack.begin(), stack.end(), A[i]) - stack.begin();
        if (where == int(stack.size()))
            stack.push_back(A[i]);
        else
            stack[where] = A[i];
    }

    cout << stack.size() << "\n";
}