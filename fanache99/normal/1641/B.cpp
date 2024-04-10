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

const int MAXN = 500;
const int MAXM = 2000000;

int v[1 + MAXM];
int sol[1 + MAXM];

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        map<int, int> par;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            par[v[i]] ^= 1;
        }
        bool bad = false;
        for (auto &it : par) {
            bad |= (it.second != 0);
        }

        if (bad) {
            cout << "-1\n";
        } else {
            vector<pair<int, int> > op;
            vector<int> t;
            int m = 0, cn = n;
            while (n > 0) {
                int j = 2;
                while (j <= n && v[j] != v[1]) {
                    j++;
                }
                assert(j <= n);
                t.push_back(2 * (j - 1));
                for (int k = 1; k < j; k++) {
                    m++;
                    sol[m] = v[k];
                }
                m++;
                sol[m] = v[1];
                for (int k = 2; k < j; k++) {
                    op.push_back({m, v[k]});
                    m++;
                    sol[m] = v[k];
                }
//                for (int k = j - 1; k > 1; k--) {
//                    m++;
//                    sol[m] = v[k];
//                }
                reverse(v + 2, v + j);
                for (int k = j; k < n; k++) {
                    v[k] = v[k + 1];
                }
                n--;
                for (int k = 1; k < n; k++) {
                    v[k] = v[k + 1];
                }
                n--;
            }
            n = cn;
            assert(op.size() <= 2 * n * n && m == n + 2 * op.size());
            cout << op.size() << "\n";
            for (auto it : op) {
                cout << it.first << " " << it.second << "\n";
            }
            cout << t.size() << "\n";
            for (auto it : t) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}