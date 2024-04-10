#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, turn;
char s[maxn];
vector<vector<int>> ans, V[2][2];
set<int> S[2];

int main() {
    scanf("%s", s + 1), n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        S[s[i] == 'R'].insert(i);
    }
    while (!S[0].empty() || !S[1].empty()) {
        turn++;
        vector<int> p0, p1;
        for (int i = 0; ; i ^= 1) {
            auto it = S[i].lower_bound(p0.empty() ? 0 : p0.back());
            if (it == S[i].end()) break;
            p0.push_back(*it), S[i].erase(it);
        }
        for (int i : p0) {
            S[s[i] == 'R'].insert(i);
        }
        for (int i = 1; ; i ^= 1) {
            auto it = S[i].lower_bound(p1.empty() ? 0 : p1.back());
            if (it == S[i].end()) break;
            p1.push_back(*it), S[i].erase(it);
        }
        if (p0.size() > p1.size()) {
            V[0][s[p0.back()] != 'R'].push_back(p0);
            for (int i : p1) {
                S[s[i] == 'R'].insert(i);
            }
            for (int i : p0) {
                S[s[i] == 'R'].erase(i);
            }
        } else {
            V[1][s[p1.back()] != 'R'].push_back(p1);
        }
    }
    printf("%d\n", turn - 1);
    cerr << "DEBUG: " << V[0][0].size() << " " << V[0][1].size() << " " << V[1][0].size() << " " << V[1][1].size() << endl;
    if (V[0][0].size() == turn) {
        for (auto &v : V[0][0]) ans.push_back(v);
    } else if (V[1][1].size() == turn) {
        for (auto &v : V[1][1]) ans.push_back(v);
    } else {
        assert(!V[0][1].empty() || !V[1][0].empty());
        assert(abs(int(V[0][1].size() - V[1][0].size())) <= 1);
        if (V[0][1].size() >= V[1][0].size()) {
            for (auto &v : V[0][0]) ans.push_back(v);
            ans.push_back(V[0][1][0]);
            for (auto &v : V[1][1]) ans.push_back(v);
            int i = 1, j = 0;
            for (int dir = 1; i < V[0][1].size() || j < V[1][0].size(); dir ^= 1) {
                if (dir == 1) ans.push_back(V[1][0][j++]);
                else ans.push_back(V[0][1][i++]);
            }
        } else {
            for (auto &v : V[1][1]) ans.push_back(v);
            ans.push_back(V[1][0][0]);
            for (auto &v : V[0][0]) ans.push_back(v);
            int i = 0, j = 1;
            for (int dir = 0; i < V[0][1].size() || j < V[1][0].size(); dir ^= 1) {
                if (dir == 1) ans.push_back(V[1][0][j++]);
                else ans.push_back(V[0][1][i++]);
            }
        }
    }
    for (auto &v : ans) {
        for (int x : v) printf("%d ", x);
    }
    return 0;
}