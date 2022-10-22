#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > E;
int been[500];

void dfs(int x) {
    been[x] = 1;
    for (auto &y: E[x])
        if (!been[y])
            dfs(y);
}

int main() {
    int N, M; cin >> N >> M;

    vector< vector<int> > A(N);
    int found;
    for (int i = 0; i < N; ++i) {
        int K; cin >> K;
        for (int j = 0; j < K; ++j) {
            int x; cin >> x;
            A[i].push_back(x);
            found = x;
        }
    }

    if (found == 0) {
        cout << N << "\n";
        return 0;
    }

    int answer = -1;
    for (int i = 0; i < N; ++i) {
        if (!A[i].size()) {
            A[i].push_back(found);
            ++answer;
        }
        sort(A[i].begin(), A[i].end());
    }

    E.resize(N);
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            vector<int> buffer(A[i].size() + A[j].size());
            if ((set_intersection(A[i].begin(), A[i].end(), A[j].begin(), A[j].end(), buffer.begin()) - buffer.begin()) > 0) {
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
    
    // now dfs
    for (int i = 0; i < N; ++i)
        if (!been[i]) {
            dfs(i);
            ++answer;
        }
    cout << answer;
}