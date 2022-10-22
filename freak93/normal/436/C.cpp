#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int N, M, K, W; cin >> N >> M >> K >> W;

    vector<string> words;
    vector< vector<int> > cost(K + 1, vector<int>(K + 1, 0));
    for (int i = 1; i <= K; ++i)
        cost[i][0] = cost[0][i] = N * M;

    for (int i = 1; i <= K; ++i) {
        string now;
        for (int j = 0; j < N; ++j) {
            string S; cin >> S;
            now += S;
        }

        words.push_back(now);

        for (int j = 0; j < i; ++j) {
            int many = 0;
            int total = N * M;
            for (int k = 0; k < total; ++k)
                if (words[j][k] != now[k])
                    ++many;
            cost[i][j + 1] = cost[j + 1][i] = many * W;
        }
    }

    vector<int> minCost = cost[0], from = vector<int>(K + 1, 0);
    minCost[0] = numeric_limits<int>::max();
    from[0] = -1;

    int answer = 0;
    vector< pair<int, int> > how;
    for (int i = 1; i <= K; ++i) {
        int nod = min_element(minCost.begin(), minCost.end()) - minCost.begin();

        how.emplace_back(nod, from[nod]);
        answer += minCost[nod];
        from[nod] = -1;
        minCost[nod] = numeric_limits<int>::max();

        for (int j = 1; j <= K; ++j)
            if (from[j] != -1) {
                if (cost[nod][j] < minCost[j]) {
                    minCost[j] = cost[nod][j];
                    from[j] = nod;
                }
            }
    }

    cout << answer << "\n";
    for (auto p : how)
        cout << p.first << " " << p.second << "\n";
}