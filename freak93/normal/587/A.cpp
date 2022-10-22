#include <iostream>
#include <vector>

using namespace std;

static const int kMaxValue = 1000 * 1000 + 40;
int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> many(kMaxValue, 0);
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        ++many[x];
    }

    int answer = 0;
    for (int i = 0; i < kMaxValue; ++i) {
        many[i + 1] += many[i] / 2;
        many[i] %= 2;
        answer += many[i];
    }

    cout << answer << "\n";
}