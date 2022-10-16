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

const int MAXN = 100000;

vector<int> g[1 + MAXN];
bool even = false, odd = false;
int subtract = 0;

void DFS(int node, int father, int depth) {
    if (g[node].size() == 1) {
        if (depth % 2 == 0)
            even = true;
        else
            odd = true;
        return;
    }
    int leaves = 0;
    for (auto son : g[node])
        if (son != father) {
            DFS(son, node, depth + 1);
            if (g[son].size() == 1)
                leaves++;
        }
    if (leaves > 1)
        subtract += leaves - 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, root;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 1) {
            root = i;
            break;
        }
    DFS(root, 0, 0);
    if (even && odd)
        cout << "3 ";
    else
        cout << "1 ";
    cout << n - 1 - subtract << "\n";
    return 0;
}