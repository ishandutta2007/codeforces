#include <bits/stdc++.h>
using namespace std;

int u, v, P;
queue<int> Q;
vector<int> V1[100], V2[100];

int inv(int x) {
    return x <= 1 ? x : 1LL * (P - P / x) * inv(P % x) % P;
}

int main() {
    scanf("%d %d %d", &u, &v, &P);
    V1[0] = {u}, V2[0] = {v};
    for (int i = 0; ; i++) {
        sort(V1[i].begin(), V1[i].end());
        V1[i].resize(unique(V1[i].begin(), V1[i].end()) - V1[i].begin());
        sort(V2[i].begin(), V2[i].end());
        V2[i].resize(unique(V2[i].begin(), V2[i].end()) - V2[i].begin());
        int d = 200 - 2 * i;
        for (int j = 0, k = 0; j < V1[i].size(); j++) {
            for (; k < V2[i].size() && V2[i][k] < V1[i][j] - d; k++);
            if (abs(V1[i][j] - V2[i][k]) <= d) {
                vector<int> ans;
                for (int $ = i - 1, x = V1[i][j]; ~$; $--) {
                    if (binary_search(V1[$].begin(), V1[$].end(), x)) {
                        continue;
                    }
                    if (binary_search(V1[$].begin(), V1[$].end(), (x + 1) % P)) {
                        ans.push_back(2), x = (x + 1) % P; continue;
                    }
                    if (binary_search(V1[$].begin(), V1[$].end(), (x + P - 1) % P)) {
                        ans.push_back(1), x = (x + P - 1) % P; continue;
                    }
                    ans.push_back(3), x = inv(x);
                }
                reverse(ans.begin(), ans.end());
                for (int x = V1[i][j], y = V2[i][k]; x ^ y; ) {
                    if (x < y) ans.push_back(1), x++;
                    else ans.push_back(2), x--;
                }
                for (int $ = i - 1, x = V2[i][k]; ~$; $--) {
                    if (binary_search(V2[$].begin(), V2[$].end(), x)) {
                        continue;
                    }
                    if (binary_search(V2[$].begin(), V2[$].end(), (x + 1) % P)) {
                        ans.push_back(1), x = (x + 1) % P; continue;
                    }
                    if (binary_search(V2[$].begin(), V2[$].end(), (x + P - 1) % P)) {
                        ans.push_back(2), x = (x + P - 1) % P; continue;
                    }
                    ans.push_back(3), x = inv(x);
                }
                printf("%d\n", ans.size());
                for (int x : ans) printf("%d ", x);
                exit(0);
            }
        }
        for (int x : V1[i]) {
            V1[i + 1].push_back(x);
            V1[i + 1].push_back((x + 1) % P);
            V1[i + 1].push_back((x + P - 1) % P);
            V1[i + 1].push_back(inv(x));
        }
        for (int x : V2[i]) {
            V2[i + 1].push_back(x);
            V2[i + 1].push_back((x + 1) % P);
            V2[i + 1].push_back((x + P - 1) % P);
            V2[i + 1].push_back(inv(x));
        }
    }
    return 0;
}