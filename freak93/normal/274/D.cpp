#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 200 * 1000 + 5;

vector<int> E[maxn], answer;
int used[maxn];
bool noanswer;

void dfs(int x) {
    used[x] = 1;
    for (auto &son: E[x])
        if (!used[son])
            dfs(son);
        else
            if (used[son] == 1)
                noanswer = true;
    answer.push_back(x);
    used[x] = 2;
}

int main() {
    int N, M; cin >> N >> M;
    vector< vector<int> > A(N, vector<int>(M));
    int nodes = M;
    for (int i = 0; i < N; ++i) {
        set< pair<int, int> > S;
        set<int> news;
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
            if (A[i][j] == -1)
                continue;
            A[i][j] *= 2;
            S.insert({A[i][j], j});
            if (news.count(A[i][j] + 1) == 0) {
                news.insert(A[i][j] + 1);
                S.insert({A[i][j] + 1, nodes++});
            }
        }

        set< pair<int, int> >::iterator it = S.begin(), jt = it, k, l;
        while (jt != S.end() && jt -> first == it -> first)
            ++jt;
        for (; jt != S.end(); it = jt, jt = l) {
            for (k = it; k != jt; ++k)
                for (l = jt; l != S.end() && l -> first == jt -> first; ++l) {
                    E[k -> second].push_back(l -> second);
                    //cerr << k -> first << " " << k -> second << " -> " << l -> first << " " << l -> second << "\n";
                }
        }
    }

    for (int i = 0; i < nodes; ++i)
        if (!used[i])
            dfs(i);
    if (noanswer) {
        cout << "-1\n";
        return 0;
    }
    reverse(answer.begin(), answer.end());
    for (auto &elem: answer) {
        if (elem < M)
            cout << elem + 1 << " ";
    }
    cout << "\n";
}