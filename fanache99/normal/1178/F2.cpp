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

const int MAXN = 500;
const int MAXM = 1000000;
const int MOD = 998244353;

int v[1 + MAXM], temp[1 + MAXN];
int dp[1 + MAXN + 1][1 + MAXN + 1];
int first[1 + MAXN], last[1 + MAXN];
vector<int> g[1 + MAXN];

int solve(int n, int val[]) {
    for (int i = n + 1; i >= 1; i--) {
        dp[i][i - 1] = 1;
        for (int j = i; j <= n; j++) {
            int smallest = MAXM, x;
            for (int k = i; k <= j; k++) {
                if (val[k] < smallest) {
                    smallest = val[k];
                    x = k;
                }
            }
            int left = 0, right = 0;
            for (int k = x; k >= i; k--) {
                left = (1LL * dp[i][k - 1] * dp[k][x - 1] + left) % MOD;
            }
            for (int k = x; k <= j; k++) {
                right = (1LL * dp[x + 1][k] * dp[k + 1][j] + right) % MOD;
            }
            dp[i][j] = 1LL * left * right % MOD;
        }
    }
    return dp[1][n];
}

bool isBad(int n, int m) {
    for (int x = 1; x <= n; x++) {
        for (int i = first[x]; i <= last[x]; i++) {
            if (v[i] < x) {
                return true;
            }
        }
    }
    return false;
}

inline bool compare(const int &a, const int &b) {
    return first[a] < first[b];
}

int DFS(int node) {
    sort(g[node].begin(), g[node].end(), compare);
    int answer = 1;
    for (int i = 0, j; i < g[node].size(); i = j + 1) {
        j = i;
        temp[1] = g[node][i];
        while (j + 1 < g[node].size() && last[g[node][j]] + 1 == first[g[node][j + 1]]) {
            j++;
            temp[j - i + 1] = g[node][j];
        }
        answer = 1LL * answer * solve(j - i + 1, temp) % MOD;
    }
    for (auto son : g[node]) {
        answer = 1LL * answer * DFS(son) % MOD;
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
        if (first[v[i]] == 0) {
            first[v[i]] = i;
        }
        last[v[i]] = i;
    }
    if (isBad(n, m)) {
        cout << "0\n";
    } else {
        first[0] = 0;
        last[0] = m + 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (first[i] > first[j] && last[i] < last[j]) {
                    g[j].push_back(i);
                    break;
                }
            }
        }
        cout << DFS(0);
    }
    //timeDuration();
    return 0;
}