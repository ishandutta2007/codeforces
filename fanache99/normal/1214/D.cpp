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

const int MAXN = 200000;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int MOD3 = 666019;

char s[1 + MAXN];

void addTo(pair<pair<int, int>, int> &x, pair<pair<int, int>, int> y) {
    x.first.first += y.first.first;
    if (x.first.first >= MOD1) {
        x.first.first -= MOD1;
    }
    x.first.second += y.first.second;
    if (x.first.second >= MOD2) {
        x.first.second -= MOD2;
    }
    x.second += y.second;
    if (x.second >= MOD3) {
        x.second -= MOD3;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<bool> > reach(n, vector<bool>(m, false));
    vector<vector<pair<pair<int, int>, int> > > dp1(n, vector<pair<pair<int, int>, int> >(m, {{0, 0}, 0}));
    vector<vector<pair<pair<int, int>, int>> > dp2(n, vector<pair<pair<int, int>, int> >(m, {{0, 0}, 0}));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reach[n - 1][m - 1] = true;
    dp2[n - 1][m - 1] = {{1, 1}, 1};
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] != '#') {
                if (i != n - 1) {
                    reach[i][j] = reach[i][j] | reach[i + 1][j];
                    addTo(dp2[i][j], dp2[i + 1][j]);
                }
                if (j != m - 1) {
                    reach[i][j] = reach[i][j] | reach[i][j + 1];
                    addTo(dp2[i][j], dp2[i][j + 1]);
                }
            }
        }
    }
    dp1[0][0] = {{1, 1}, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '#') {
                if (i != 0) {
                    addTo(dp1[i][j], dp1[i - 1][j]);
                }
                if (j != 0) {
                    addTo(dp1[i][j], dp1[i][j - 1]);
                }
            }
        }
    }
    if (!reach[0][0]) {
        cout << "0\n";
    } else {
        if (n == 1 || m == 1) {
            cout << "1\n";
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (make_pair(i, j) != make_pair(0, 0) && make_pair(i, j) != make_pair(n - 1, m - 1)) {
                        if (1LL * dp1[i][j].first.first * dp2[i][j].first.first % MOD1 == dp2[0][0].first.first &&
                            1LL * dp1[i][j].first.second * dp2[i][j].first.second % MOD2 == dp2[0][0].first.second &&
                            1LL * dp1[i][j].second * dp2[i][j].second % MOD3 == dp2[0][0].second) {
                            cout << "1\n";
                            return 0;
                        }
                    }
                }
            }
            cout << "2\n";
        }
    }
    //timeDuration();
    return 0;
}