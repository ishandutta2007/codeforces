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
#include <cmath>
#include <iomanip>
#include <iterator>

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
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
bool seen[1 + MAXN];
int depth[1 + MAXN], dad[1 + MAXN], k;

void cycle(int first, int last) {
    vector<int> answer;
    int node = first;
    while (node != last) {
        answer.emplace_back(node);
        node = dad[node];
    }
    answer.emplace_back(last);
    cout << "2\n" << answer.size() << "\n";
    for (auto it : answer) {
        cout << it << " ";
    }
}

void DFS(int node, int parent) {
    seen[node] = true;
    depth[node] = depth[parent] + 1;
    dad[node] = parent;
    for (auto neighbour : g[node]) {
        if (!seen[neighbour]) {
            DFS(neighbour, node);
        } else if (neighbour != parent && depth[neighbour] < depth[node] && depth[node] - depth[neighbour] + 1 <= k) {
            cycle(node, neighbour);
            exit(0);
        }
    }
}

int main() {
    timeBegin();
    //InputReader cin("input.in");
    //ofstream cout("output.txt");
    int n, m;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    DFS(1, 0);
    vector<int> parity[2];
    for (int i = 1; i <= n; i++) {
        if (depth[i] <= k) {
            parity[depth[i] % 2].emplace_back(i);
        }
    }
    if (parity[0].size() < parity[1].size()) {
        swap(parity[0], parity[1]);
    }
    cout << "1\n";
    for (int i = 0; i < (k + 1) / 2; i++) {
        cout << parity[0][i] << " ";
    }
    //timeDuration();
    return 0;
}