#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        --C[i];
    }

    vector<bool> used(N, false);
    vector< vector<int> > cycles;
    for (int i = 0; i < N; ++i) {
        if (used[C[i]])
            continue;
        vector<int> aux;
        for (int j = i; !used[C[j]]; j = C[j]) {
            used[C[j]] = true;
            aux.push_back(C[j]);
        }
        if (aux.size() > 1)
            cycles.push_back(aux);
    }

    vector< pair<int, int> > answer;
    for (int i = 1; i < int(cycles.size()); i += 2) {
        auto &a = cycles[i - 1];
        auto &b = cycles[i];

        answer.emplace_back(a.back(), b.back());
        for (int j = 0; j < int(b.size()) - 1; ++j)
            answer.emplace_back(a.back(), b[j]);
        for (int j = 0; j < int(a.size()) - 1; ++j)
            answer.emplace_back(b.back(), a[j]);
        answer.emplace_back(a.back(), b.back());
    }

    if (cycles.size() % 2) {
        used.assign(N, false);
        auto &b = cycles.back();
        for (auto &x : b)
            used[x] = true;


        if (b.size() == 2) {
            int extra = -1;
            for (int i = 0; i < N; ++i)
                if (!used[i]) 
                    extra = i;
            answer.emplace_back(extra, b[0]);
            answer.emplace_back(extra, b[1]);
            answer.emplace_back(extra, b[0]);
        } else if (b.size() == 3) {
            answer.emplace_back(b[0], b[1]);
            answer.emplace_back(b[1], b[2]);
            answer.emplace_back(b[0], b[2]);
            answer.emplace_back(b[0], b[1]);
        } else {
            answer.emplace_back(b.back(), b[1]);
            answer.emplace_back(b[0], b[2]);
            for (int i = 3; i < int(b.size()) - 1; ++i)
                answer.emplace_back(b[0], b[i]);
            answer.emplace_back(b.back(), b[0]);
            answer.emplace_back(b[0], b[1]);
            answer.emplace_back(b[1], b[2]);
        }
    }

    cout << answer.size() << "\n";
    for (auto &p : answer)
        cout << p.first + 1 << " " << p.second  + 1 << "\n";
}