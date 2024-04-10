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

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
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

const int MAXN = 75;
const long long INF = 1000000000000000000LL;

int a[1 + MAXN], b[1 + MAXN];

long long check(vector<int> op, int n, int k) {
    long long answer = 0;
    int have = 0;
    vector<int> seen(n + 1, 0);
    vector<long long> add(n + 1, 0);
    for (auto it : op) {
        if (it > 0) {
            if (it > n || seen[it] != 0)
                return -1;
            answer += a[it] + 1LL * have * b[it];
            for (int j = 1; j <= n; j++)
                if (seen[j] == 1)
                    add[j] += b[it];
            have++;
            seen[it] = 1;
            add[it] = a[it];
        } else {
            if (-it > n || seen[-it] != 1)
                return -1;
            have--;
            answer -= add[-it];
            seen[-it] = 2;
        }
        if (have > k)
            return -1;
    }
    return answer;
}

struct Minion {
    int a;
    int b;
    int id;

    bool operator < (const Minion &other) const {
        return b < other.b;
    }
};

Minion v[1 + MAXN];
long long dp[1 + MAXN][1 + MAXN];
bool take[1 + MAXN][1 + MAXN];

int main() {
    //ifstream cin("input.in");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            v[i] = {a[i], b[i], i};
        }
        sort(v + 1, v + n + 1);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = -INF;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + 1LL * (k - 1) * v[i].b;
            take[i][0] = false;
            for (int j = 1; j <= i; j++)
                if (dp[i - 1][j] + 1LL * (k - 1) * v[i].b > dp[i - 1][j - 1] + v[i].a + 1LL * (j - 1) * v[i].b) {
                    dp[i][j] = dp[i - 1][j] + 1LL * (k - 1) * v[i].b;
                    take[i][j] = false;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + v[i].a + 1LL * (j - 1) * v[i].b;
                    take[i][j] = true;
                }
        }
        //cout << dp[n][k] << "\n";
        vector<int> in, out, solution;
        for (int i = n, j = k; i >= 1; i--)
            if (take[i][j]) {
                in.emplace_back(v[i].id);
                j--;
            }
            else
                out.emplace_back(v[i].id);
        reverse(in.begin(), in.end());
        for (int i = 0; i < k - 1; i++)
            solution.emplace_back(in[i]);
        for (auto it : out) {
            solution.emplace_back(it);
            solution.emplace_back(-it);
        }
        solution.emplace_back(in[k - 1]);
        //cout << check(solution, n, k) << "\n";
        cout << solution.size() << "\n";
        for (auto it : solution)
            cout << it << " ";
        cout << "\n";
        /*vector<int> good;
        int goodSize;
        cin >> goodSize;
        for (int i = 0; i < goodSize; i++) {
            int x;
            cin >> x;
            good.emplace_back(x);
        }
        cout << check(good, n, k) << "\n";*/
    }
    return 0;
}