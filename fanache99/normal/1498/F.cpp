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
#include <unordered_map>

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

const int MAXN = 100000;
const int MAXK = 20;

int k;
vector<int> g[1 + MAXN];
int v[1 + MAXN];
int answer[1 + MAXN], sum[1 + MAXN][2 * MAXK], current[2 * MAXK], temp[2 * MAXK];

void DFS(int node, int father) {
    sum[node][0] ^= v[node];
    for (auto son : g[node]) {
        if (son != father) {
            DFS(son, node);
            for (int i = 0; i < (2 * k); i++) {
                sum[node][(i + 1) % (2 * k)] ^= sum[son][i];
            }
        }
    }
}

void shift(int x) {
    for (int i = 0; i < 2 * k; i++) {
        temp[(i + x + 2 * k) % (2 * k)] = current[i];
    }
    for (int i = 0; i < 2 * k; i++) {
        current[i] = temp[i];
    }
}

void solve(int node, int father) {
    answer[node] = 0;
    for (int i = k; i < 2 * k; i++) {
        answer[node] ^= current[i];
    }
    for (auto son : g[node]) {
        if (son != father) {
            for (int i = 0; i < 2 * k; i++) {
                current[(i + 1) % (2 * k)] ^= sum[son][i];
            }
            shift(1);
            for (int i = 0; i < 2 * k; i++) {
                current[i] ^= sum[son][i];
            }
            solve(son, node);
            for (int i = 0; i < 2 * k; i++) {
                current[i] ^= sum[son][i];
            }
            shift(-1);
            for (int i = 0; i < 2 * k; i++) {
                current[(i + 1) % (2 * k)] ^= sum[son][i];
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    DFS(1, 0);
    for (int i = 0; i < (2 * k); i++) {
        current[i] = sum[1][i];
    }
    solve(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << (answer[i] != 0) << " ";
    }
    //timeDuration();
    return 0;
}