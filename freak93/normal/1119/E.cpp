#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    int left_overs = 0;
    int64_t answer = 0;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;

        int with_left_overs = min(left_overs, x / 2);
        answer += with_left_overs;
        left_overs -= with_left_overs;
        x -= with_left_overs * 2;
        answer += x / 3;
        left_overs += x % 3;
    }

    cout << answer << "\n";
}