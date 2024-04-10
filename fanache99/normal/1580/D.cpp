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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 4000;
const int INF = (1 << 31) - 1;

int v[1 + MAXN];

struct Node {
    int weight;
    int mn;
    vector<long long> dp;
};

int m;

Node solve(int l, int r) {
    if (l > r) {
        return {0, INF, {0}};
    }
    Node ans;
    ans.weight = r - l + 1;
    ans.dp.resize(ans.weight + 1);
    ans.mn = INF;
    int mid;
    for (int i = l; i <= r; i++) {
        if (v[i] < ans.mn) {
            ans.mn = v[i];
            mid = i;
        }
    }

    Node left = solve(l,  mid - 1), right = solve(mid + 1, r);
    assert(left.weight + right.weight + 1 == ans.weight);

    for (int a = 0; a <= left.weight && a <= m; a++) {
        for (int b = 0; b <= right.weight && b <= m; b++) {
            long long curr = left.dp[a] + right.dp[b] + 1LL * a * (m - a) * (left.mn - ans.mn) + 1LL * b * (m - b) * (right.mn - ans.mn);
            ans.dp[a + b] = max(ans.dp[a + b], curr);
            ans.dp[a + b + 1] = max(ans.dp[a + b + 1], curr);
        }
    }

    return ans;
}

int main() {
    timeBegin();
    //  ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    Node ans = solve(1, n);
    cout << ans.dp[m] << "\n";
    return 0;
}