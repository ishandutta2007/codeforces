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
    timeEnd();
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

const int MAXN = 300000;

char s[1 + MAXN];
vector<pair<int, int> > g[1 + MAXN][2];
bool seen[1 + MAXN][2];
int answer[1 + MAXN];
vector<int> nodes, start;

void DFS(int node, int parity) {
    seen[node][parity] = true;
    nodes.push_back(node);
    if (parity == 0) {
        start.push_back(node);
    }
    for (auto it : g[node][parity]) {
        if (!seen[it.first][it.second]) {
            DFS(it.first, it.second);
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n >> (s + 1);
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') {
                g[i][0].push_back(make_pair(i - 1, 1));
                g[i - 1][1].push_back(make_pair(i, 0));
            } else {
                g[i][1].push_back(make_pair(i - 1, 0));
                g[i - 1][0].push_back(make_pair(i, 1));
            }
        }
        for (int i = 0; i <= n; i++) {
            if (!seen[i][0]) {
                nodes.clear();
                start.clear();
                DFS(i, 0);
                sort(nodes.begin(), nodes.end());
                nodes.resize(unique(nodes.begin(), nodes.end()) - nodes.begin());
                for (auto it : start) {
                    answer[it] = nodes.size();
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            cout << answer[i] << " ";
            seen[i][0] = seen[i][1] = false;
            g[i][0].clear();
            g[i][1].clear();
        }
        cout << "\n";
    }
    //timeDuration();
    return 0;
}