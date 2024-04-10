#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int v[1 + MAXN];
vector<pair<int, int> > answer;
vector<int> level[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, t, k;
    scanf("%d%d%d", &n, &t, &k);
    for (int i = 1; i <= t; i++)
        scanf("%d", &v[i]);
    level[0].push_back(1);
    int number = 1;
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= v[i]; j++) {
            number++;
            level[i].push_back(number);
        }
    int nodes = n - 1 - k - (t - 1);
    if (nodes < 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= t; i++)
        answer.push_back(make_pair(level[i - 1][0], level[i][0]));
    for (int i = 1; i < level[1].size(); i++)
        answer.push_back(make_pair(1, level[1][i]));
    for (int k = 1; k < t; k++) {
        int i = 1, j = 1;
        while (nodes && i < level[k].size() && j < level[k + 1].size()) {
            nodes--;
            answer.push_back(make_pair(level[k][i], level[k + 1][j]));
            i++;
            j++;
        }
        while (j < level[k + 1].size()) {
            answer.push_back(make_pair(level[k][0], level[k + 1][j]));
            j++;
        }
    }
    if (nodes) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", n);
    for (auto &it : answer)
        printf("%d %d\n", it.first, it.second);
    return 0;
}