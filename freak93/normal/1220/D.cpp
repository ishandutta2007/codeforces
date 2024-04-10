#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int64_t> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];

    vector<int64_t> answer = V;

    vector<int64_t> aux;
    int64_t step = 0;
    while (V.size()) {
        // maybe keep the odds
        size_t odds = 0;
        for (auto &x : V)
            if (x % 2)
                ++odds;
        if (aux.size() + V.size() - size_t(odds) < answer.size()) {
            answer.clear();
            answer.insert(answer.end(), aux.begin(), aux.end());
            for (auto &x : V)
                if (x % 2 == 0)
                    answer.push_back(x << step);
        }

        // continue with the even ones
        for (auto &x : V)
            if (x % 2 == 1)
                aux.push_back(x << step);

        V.erase(remove_if(V.begin(), V.end(), [&](int64_t x) { 
            return x % 2 == 1;
        }), V.end());
        for (auto &x : V)
            x /= 2;
        step++;
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for (auto &x : answer)
        cout << x << " ";
    cout << "\n";
}