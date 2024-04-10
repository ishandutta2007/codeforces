#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 5000;
const int INF = 1000000001;

vector<pair<int, int> > g[1 + MAXN], gt[1 + MAXN];
int degree[1 + MAXN];
int dp[1 + MAXN][1 + MAXN], dad[1 + MAXN][1 + MAXN];
int order[1 + MAXN];
vector<int> visits;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, limit;
    scanf("%d%d%d", &n, &m, &limit);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        gt[b].push_back(make_pair(a, c));
        degree[b]++;
    }
    int left = 1, right = 0;
    for (int i = 1; i <= n; i++)
        if (!degree[i]) {
            right++;
            order[right] = i;
        }
    while (left <= right) {
        int node = order[left];
        left++;
        for (auto &son : g[node]) {
            degree[son.first]--;
            if (!degree[son.first]) {
                right++;
                order[right] = son.first;
            }
        }
        if (node == 1)
            dp[node][1] = 0;
        else
            dp[node][1] = INF;
        for (int cities = 2; cities <= n; cities++) {
            dp[node][cities] = INF;
            for (auto &before : gt[node])
                if (dp[before.first][cities - 1] + before.second < dp[node][cities]) {
                    dp[node][cities] = dp[before.first][cities - 1] + before.second;
                    dad[node][cities] = before.first;
                }
        }
    }
    int answer;
    for (int i = n; i >= 1; i--)
        if (dp[n][i] <= limit) {
            answer = i;
            break;
        }
    printf("%d\n", answer);
    int node = n, cities = answer;
    while (node) {
        visits.push_back(node);
        node = dad[node][cities];
        cities--;
    }
    for (int i = visits.size() - 1; i >= 0; i--)
        printf("%d ", visits[i]);
    return 0;
}