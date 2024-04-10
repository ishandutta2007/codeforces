#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N, M, T; cin >> N >> M >> T;

    vector<int> time(N);
    for (int i = 0; i < N; ++i) {
        int x, y, z; char c;
        cin >> x >> c >> y >> c >> z;
        time[i] = x * 3600 + y * 60 + z;
    }

    int current = 0;
    vector<int> answer(N);
    multiset<int> still;
    bool good = false;
    for (int i = 0; i < N; ++i) {
        while (still.size() && *still.begin() < time[i])
            still.erase(still.begin());
        if (int(still.size()) == M) {
            answer[i] = current;
            if (i > 0 && still.count(time[i - 1] + T - 1))
                still.erase(still.find(time[i - 1] + T - 1));
        } else
            answer[i] = ++current;
        still.insert(time[i] + T - 1);
        if (int(still.size()) == M)
            good = true;
    }

    if (!good) {
        cout << "No solution\n";
        return 0;
    } else {
        cout << current << "\n";
        for (auto &x : answer)
            cout << x << "\n";
    }
}