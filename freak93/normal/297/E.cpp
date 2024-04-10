#include <iostream>
#include <vector>

using namespace std;

const int maxn = 400505;

int N;
vector<int> Start[maxn], End[maxn];
int aibstart[maxn], aibend[maxn];

void update(int *aib, int poz, int value) {
    for (; poz <= 2 * N; poz += (poz & -poz))
        aib[poz] += value;
}

int query(int *aib, int to) {
    int answer = 0;
    for (; to > 0; to -= (to & -to))
        answer += aib[to];
    return answer;
}

int query(int *aib, int from, int to) {
    if (from > to)
        return 0;
    return query(aib, to) - query(aib, from - 1);
}

int main() {
    cin >> N;
    N *= 2;
    for (int i = 0; i < N / 2; ++i) {
        int x, y; cin >> x >> y;
        if (x > y)
            swap(x, y);

        Start[x].push_back(y);
        End[y].push_back(x);

        x += N;
        Start[y].push_back(x);
        End[x].push_back(y);

        y += N;
        Start[x].push_back(y);
        End[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
        for (auto &x: End[i]) {
            update(aibstart, x, 1);
            update(aibend, i, 1);
        }

    long long answer = 1LL * (N / 2) * (N / 2- 1) * (N / 2 - 2) / 3;
    for (int i = 1; i <= N; ++i) {
        for (auto &y: Start[i]) {
            // 2 0 0
            answer -= 1LL * query(aibend, i + 1, y - 1) * query(aibstart, y + 1, i + N - 1);

            // 2 1 1 and 1 1 0
            answer -= 1LL * query(aibend, i + 1, y - 1) * (query(aibstart, i + 1, y - 1) - query(aibend, i + 1, y - 1) );
        }

        for (auto &y: Start[i]) {
            update(aibstart, i, -1);
            update(aibend, y, -1);
        }

        for (auto &x: End[i + N]) {
            update(aibstart, x, 1);
            update(aibend, i + N, 1);
        }
    }

    answer /= 2;
    cout << answer << "\n";
}