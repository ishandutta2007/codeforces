#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;

    int first; cin >> first;
    int first_different = -1;
    int answer = 0;
    for (int i = 1; i < N; ++i) {
        int x; cin >> x;
        if (x != first) {
            answer = max(answer, i);
            if (first_different == -1)
                first_different = i;
        } else if (first_different != -1)
            answer = max(answer, i - first_different);
    }

    cout << answer << "\n";
}