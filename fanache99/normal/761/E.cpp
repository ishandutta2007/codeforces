//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 30;

vector<int> g[1 + MAXN];
pair<long long, long long> answer[1 + MAXN];
int line[4] = {1, 0, 0, -1};
int column[4] = {0, 1, -1, 0};
bool seen[1 + MAXN];

void Add(int &x) {
    x++;
    if (x == 4)
        x = 0;
}

void Solve(int node, long long x, long long y, long long step, int bad) {
    seen[node] = true;
    int direction = 0;
    for (auto &son : g[node])
        if (!seen[son]) {
            if (direction == bad)
                Add(direction);
            long long x0 = x + step * line[direction];
            long long y0 = y + step * column[direction];
            answer[son] = make_pair(x0, y0);
            Solve(son, x0, y0, step / 2, 3 - direction);
            Add(direction);
        }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 4) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    int root = 1;
    for (int i = 1; i <= n; i++)
        if (g[i].size() == 4) {
            root = i;
            break;
        }
    answer[root] = make_pair(1LL << n, 1LL << n);
    Solve(root, 1LL << n, 1LL << n, 1LL << (n - 1), 4);
    for (int i = 1; i <= n; i++)
        cout << answer[i].first << " " << answer[i].second << "\n";
    return 0;
}