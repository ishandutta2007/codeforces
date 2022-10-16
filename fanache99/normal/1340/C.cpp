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

const int MAXM = 10000;
const int MAXG = 1000;
const int MAXR = 1000;
const long long INF = 1000000000000000000LL;

int v[1 + MAXM];
long long best[1 + MAXM][MAXG];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> v[i];
    sort(v + 1, v + m + 1);
    int green, red;
    cin >> green >> red;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < green; j++)
            best[i][j] = INF;
    deque<pair<int, int> > d;
    best[1][0] = 0;
    d.push_back(make_pair(1, 0));
    while (!d.empty()) {
        int node = d.front().first, t = d.front().second;
        d.pop_front();
        if (node != 1 && v[node] - v[node - 1] <= green - t) {
            int newT = t + v[node] - v[node - 1];
            if (newT == green) {
                newT = 0;
                if (best[node][t] + 1 < best[node - 1][newT]) {
                    best[node - 1][newT] = best[node][t] + 1;
                    d.push_back(make_pair(node - 1, newT));
                }
            }
            else
                if (best[node][t] < best[node - 1][newT]) {
                    best[node - 1][newT] = best[node][t];
                    d.push_front(make_pair(node - 1, newT));
                }
        }
        if (node != m && v[node + 1] - v[node] <= green - t) {
            int newT = t + v[node + 1] - v[node];
            if (newT == green) {
                newT = 0;
                if (best[node][t] + 1 < best[node + 1][newT]) {
                    best[node + 1][newT] = best[node][t] + 1;
                    d.push_back(make_pair(node + 1, newT));
                }
            }
            else
                if (best[node][t] < best[node + 1][newT]) {
                    best[node + 1][newT] = best[node][t];
                    d.push_front(make_pair(node + 1, newT));
                }
        }
    }
    long long answer = INF;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < green; j++)
            if (v[m] - v[i] <= green - j && best[i][j] != INF)
                answer = min(answer, 1LL * (red + green) * best[i][j] + j + v[m] - v[i]);
    if (answer == INF)
        cout << "-1\n";
    else
        cout << answer << "\n";
    return 0;
}