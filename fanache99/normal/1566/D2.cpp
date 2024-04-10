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

const int MAXN = 300;

pair<int, int> seat[1 + MAXN * MAXN];
int fenwick[1 + MAXN][1 + MAXN];

void update(int v[], int x, int m) {
    for (; x <= m; x += (x & -x)) {
        v[x]++;
    }
}

int query(int v[], int x) {
    int ans = 0;
    for (; x > 0; x -= (x & -x)) {
        ans += v[x];
    }
    return ans;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        map<int, vector<int> > sight;
        for (int i = 1; i <= n * m; i++) {
            int x;
            cin >> x;
            sight[x].push_back(i);
        }
        int r = 1, c = 1;
        for (auto &it : sight) {
            int cnt = it.second.size();
            vector<pair<int, int> > seats;
            while (cnt > 0) {
                int x = min(cnt, m - c + 1);
                for (int col = c + x - 1; col >= c; col--) {
                    seats.push_back({r, col});
                }
                cnt -= x;
                c += x;
                if (c > m) {
                    r++;
                    c = 1;
                }
            }
            assert(seats.size() == it.second.size());
            for (int i = 0; i < seats.size(); i++) {
                seat[it.second[i]] = seats[i];
            }
        }
        assert(r == n + 1 && c == 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                fenwick[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n * m; i++) {
            r = seat[i].first, c = seat[i].second;
            ans += query(fenwick[r], c);
            update(fenwick[r], c, m);
        }
        cout << ans << "\n";
    }
    return 0;
}