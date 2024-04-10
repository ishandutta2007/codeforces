#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 200000;

vector<int> g[1 + MAXN];
vector<int> added;
int weight[1 + MAXN], depth[1 + MAXN];

void DFS(int node, int father) {
    depth[node] = depth[father] + 1;
    weight[node] = 1;
    for (auto son : g[node])
        if (son != father) {
            DFS(son, node);
            weight[node] += weight[son];
        }
    added.emplace_back(depth[node] - weight[node]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    DFS(1, 0);
    sort(added.begin(), added.end());
    reverse(added.begin(), added.end());
    long long answer = 0;
    for (int i = 0; i < k; i++)
        answer += added[i];
    cout << answer << "\n";
    return 0;
}