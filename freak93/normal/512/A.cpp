#include <iostream>
#include <vector>

using namespace std;

int edge[26][26];
int used[30];
int answer[30];

bool dfs(int x) {
    used[x] = 1;
    for (int i = 0; i < 26; ++i)
        if (edge[x][i]) {
            if (used[i] == 1)
                return false;
            if (used[i] == 0)
                if (!dfs(i))
                    return false;
        }
    used[x] = 2;
    answer[++answer[0]] = x;
    return true;
}

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];


    for (int i = 1; i < N; ++i) {
        bool breaked = false;
        for (int j = 0; j < int(S[i].size()) && j < int(S[i - 1].size()); ++j)
            if (S[i][j] != S[i - 1][j]) {
                edge[S[i - 1][j] - 'a'][S[i][j] - 'a'] = 1;
                breaked = true;
                break;
            }
        if (!breaked && S[i].size() < S[i - 1].size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < 26; ++i)
        if (!used[i])
            if (!dfs(i)) {
                cout << "Impossible\n";
                return 0;
            }

    for (int i = 26; i > 0; --i)
        cout << char(answer[i] + 'a');
    cout << "\n";
}