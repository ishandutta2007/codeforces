#include <iostream>
#include <vector>

using namespace std;

const int maxn = 100 * 1000 + 5;

vector<int> E[maxn];
long long V[maxn];
long long dp[maxn];
long long add[maxn];
long long substract[maxn];

bool used[maxn];

void dfs(int nod) {
    used[nod] = true;

    for (auto &son: E[nod])
        if (!used[son]) {
            dfs(son);
            add[nod] = max(add[nod], add[son]);
            substract[nod] = max(substract[nod], substract[son]);
        }

    V[nod] += add[nod] - substract[nod];
    if (V[nod] < 0) {
        add[nod] -= V[nod];
    } else {
        substract[nod] += V[nod];
    }
}

int N;

int main() {
    cin >> N;
    for (int i = 1; i < N; ++i) {
        int x, y; cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
        cin >> V[i];
    dfs(1);

    cout << add[1] + substract[1] << "\n";
}