#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>

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

const int MAXN = 18;

char edge[MAXN][MAXN];
int n;
vector<int> v;
map<vector<int>, long long> ways;
long long dp[MAXN][1 << MAXN];
long long paths[MAXN + 1][1 << MAXN];
long long temp[1 << MAXN];
long long answer[1 << (MAXN - 1)];

void SOS(long long *a, int m, int sign) {
    for (int mask = 0; mask < (1 << m); mask++)
        temp[mask] = a[mask];
    for (int i = 0; i < m; i++)
        for (int mask = 0; mask < (1 << m); mask++)
            if (mask & (1 << i))
                temp[mask] += sign * temp[mask ^ (1 << i)];
    for (int mask = 0; mask < (1 << m); mask++)
        a[mask] = temp[mask];
}

void precompute() {
    for (int mask = 1; mask < (1 << n); mask++)
        for (int bit = 0; bit < n; bit++)
            if (mask & (1 << bit)) {
                dp[bit][mask] = 0;
                if ((1 << bit) == mask)
                    dp[bit][mask] = 1;
                else
                    for (int before = 0; before < n; before++)
                        if (mask & (1 << before) && edge[before][bit] == '1')
                            dp[bit][mask] += dp[before][mask ^ (1 << bit)];
                paths[__builtin_popcount(mask)][mask] += dp[bit][mask];
            }
    for (int i = 1; i <= n; i++)
        SOS(paths[i], n, 1);
}

void compute() {
    long long answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        long long current = 1;
        for (auto x : v)
            current *= paths[x][mask];
        if (__builtin_popcount(((1 << n) - 1)^ mask) % 2 == 0)
            answer += current;
        else
            answer -= current;
    }
    ways[v] = answer;
}

void partitions(int s) {
    if (s == 0) {
        compute();
        return;
    }
    int start = 1;
    if (!v.empty())
        start = v.back();
    for (int x = start; x <= s; x++) {
        v.push_back(x);
        partitions(s - x);
        v.pop_back();
    }
}

vector<int> getPartition(int mask) {
    vector<int> answer;
    int length = 1, sum = 0;
    for (int i = 0; i < n - 1; i++)
        if (mask & (1 << i))
            length++;
        else {
            answer.push_back(length);
            sum += length;
            length = 1;
        }
    sum += length;
    assert(sum == n);
    answer.push_back(length);
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> edge[i];
    precompute();
    partitions(n);
    for (int mask = 0; mask < (1 << (n - 1)); mask++)
        answer[((1 << (n - 1)) - 1) ^ mask] = ways[getPartition(mask)];
    SOS(answer, n - 1, -1);
    for (int mask = 0; mask < (1 << (n - 1)); mask++)
        cout << answer[((1 << (n - 1)) - 1)  ^ mask] << " ";
    return 0;
}