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
#include <bitset>
#include <unordered_set>

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
    inline InputReader &operator >>(long long &n) {
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
const int MOD = 666013;
const int BASE = 1000000007;

vector<pair<int, int> > table[MOD];
vector<int> g[1 + MAXN], sol;
int degree[1 + MAXN];
bool out[1 + MAXN], found;

int code(int a, int b) {
    return (1LL * a * BASE + b) % MOD;
}

void erase(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    int h = code(a, b);
    table[h].clear();
}

void insert(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    int h = code(a, b);
    table[h].push_back(make_pair(a, b));
}

bool find(int a, int b) {
    if (a > b) {
        swap(a, b);
    }
    int h = code(a, b);
    for (auto it : table[h]) {
        if (it.first == a && it.second == b) {
            return true;
        }
    }
    return false;
}

void check(int node) {
    vector<int> nodes;
    for (auto it : g[node]) {
        if (!out[it]) {
            nodes.push_back(it);
        }
    }
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = i + 1; j < nodes.size(); j++) {
            if (!find(nodes[i], nodes[j])) {
                return;
            }
        }
    }
    found = true;
    sol = nodes;
    sol.push_back(node);
}

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
            insert(a, b);
            degree[a]++;
            degree[b]++;
        }
        if (1LL * (k - 1) * (k - 2) / 2 > m) {
            cout << "-1\n";
        } else {
            found = false;
            sol.clear();
            queue<int> q;
            for (int i = 1; i <= n; i++) {
                if (degree[i] == k - 1) {
                    check(i);
                    if (found) {
                        break;
                    }
                }
                if (degree[i] < k) {
                    q.push(i);
                }
            }
            while (!found && !q.empty()) {
                int node = q.front();
                q.pop();
                out[node] = true;
                for (auto it : g[node]) {
                    degree[it]--;
                    if (degree[it] == k - 1) {
                        check(it);
                        q.push(it);
                    }
                }
            }
            if (found) {
                cout << "2\n";
                for (auto it : sol) {
                    cout << it << " ";
                }
                cout << "\n";
            } else {
                for (int i = 1; i <= n; i++) {
                    if (!out[i]) {
                        sol.push_back(i);
                    }
                }
                if (!sol.empty()) {
                    found = true;
                }
                if (!found) {
                    cout << "-1\n";
                } else {
                    cout << "1 " << sol.size() << "\n";
                    for (auto it : sol) {
                        cout << it << " ";
                    }
                    cout << "\n";
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (auto it : g[i]) {
                erase(i, it);
            }
            g[i].clear();
            out[i] = false;
            degree[i] = 0;
        }
    }
    return 0;
}