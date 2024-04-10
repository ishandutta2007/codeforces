#include <iostream>
#include <vector>

using namespace std;

int zeros(int X) {
    if (X == 0)
        return 0;
    return X / 5 + zeros(X / 5);
};

int main() {
    int M; cin >> M;

    vector<int> answer;
    int x = 1;
    while (zeros(x) < M)
        ++x;
    while (zeros(x) == M)
        answer.push_back(x++);

    cout << answer.size() << "\n";
    for (auto &x : answer)
        cout << x << " ";
    cout << "\n";
}