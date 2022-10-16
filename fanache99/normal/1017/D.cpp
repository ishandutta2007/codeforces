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
#include <unordered_map>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
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

const int MAXM = 500000;
const int MAXN = 12;
const int MAXW = 100;

int w[MAXN], have[1 << MAXN];
int v[1 + MAXM], ans[1 + MAXM];
vector<pair<int, int> > qs[1 + MAXM];
int sum[1 + MAXW + 1];

int value(string &s) {
    int x = 0;
    for (int j = 0; j < s.size(); j++) {
        x |= (1 << j) * (s[j] - '0');
    }
    return x;
}

int cost(int x, int y, int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((((x ^ y) >> i) & 1) == 0) {
            ans += w[i];
        }
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        v[i] = value(s);
        have[v[i]]++;
    }
    for (int i = 1; i <= q; i++) {
        string s;
        int l;
        cin >> s >> l;
        qs[value(s)].push_back({l, i});
    }
    for (int i = 0; i < (1 << n); i++) {
        vector<pair<int, int> > c;
        for (int j = 0; j < (1 << n); j++) {
            sum[min(cost(i, j, n), MAXW + 1)] += have[j];
        }
        for (int j = 1; j <= MAXW + 1; j++) {
            sum[j] += sum[j - 1];
        }
        for (auto it : qs[i]) {
            ans[it.second] = sum[it.first];
        }
        for (int j = 0; j <= MAXW + 1; j++) {
            sum[j] = 0;
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}