#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>

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

const int MAXN = 100000;

vector<int> g[1 + MAXN];
vector<pair<int, int> > answer;
int limit = 0;

void DFS(int node, int father, int value) {
    answer.emplace_back(make_pair(node, value));
    int sons = 0, initial = value;
    for (auto son : g[node])
        if (son != father)
            sons++;
    for (auto son : g[node])
        if (son != father) {
            if (value == limit) {
                value = initial - sons - 1;
                answer.emplace_back(make_pair(node, value));
            }
            DFS(son, node, value + 1);
            value++;
            answer.emplace_back(make_pair(node, value));
            sons--;
        }
    if (value >= initial && node != 1)
        answer.emplace_back(make_pair(node, initial - 1));
}

bool visited[1 + MAXN];
map<pair<int, int>, bool> seen;

bool check(int n) {
    if (answer[0] != make_pair(1, 0) || answer.back().first != 1)
        return false;
    pair<int, int> before = make_pair(0, 0);
    for (auto it : answer) {
        visited[it.first] = true;
        if (seen[it] || it.second > limit || it.second < 0)
            return false;
        seen[it] = true;
        if (before.first != 0)
            if (!((before.first != it.first && before.second + 1== it.second) || (before.first == it.first && before.second > it.second)))
                return false;
        before = it;
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++)
        limit = max(limit, (int) g[i].size());
    DFS(1, 0, 0);
    //assert(check(n));
    cout << answer.size() << "\n";
    for (auto it : answer)
        cout << it.first << " " << it.second << "\n";
    return 0;
}