#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M; cin >> N >> M;

    auto need = [&](int many) {
        if (many % 2 == 0)
            return many * many / 2;
        return many * (many - 1) / 2 + 1;
    };
    int many = 0;
    for (many = 1; need(many) <= N; ++many);
    --many;

    vector< pair<int, int> > V(M);
    for (int i = 0; i < M; ++i)
        cin >> V[i].second >> V[i].first;
    sort(V.begin(), V.end(), greater< pair<int ,int> >());

    int answer = 0;
    for (int i = 0; i < many and i < int(V.size()); ++i)
        answer += V[i].first;
    cout << answer << "\n";
}