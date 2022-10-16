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

const int MAXN = 2021;

int v[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            bad |= (v[i] % 2 != i % 2);
        }
        if (bad) {
            cout << "-1\n";
        } else {
            vector<int> sol;
            for (int k = n; k > 1; k -= 2) {
                int a = 0;
                for (int i = 1; i <= k; i++) {
                    if (v[i] == k) {
                        a = i;
                        break;
                    }
                }
                assert(a != 0 && a % 2 == 1);
                sol.push_back(a);
                reverse(v + 1, v + a + 1);
                int b = 0;
                for (int i = 1; i <= k; i++) {
                    if (v[i] == k - 1) {
                        b = i;
                        break;
                    }
                }
                assert(b != 0 && b % 2 == 0);
                sol.push_back(b - 1);
                reverse(v + 1, v + b);
                assert(v[b] == k - 1 && v[b - 1] == k);
                sol.push_back(b + 1);
                reverse(v + 1, v + b + 2);
                assert(v[2] == k - 1 && v[3] == k);
                sol.push_back(3);
                reverse(v + 1, v + 4);
                assert(v[1] == k && v[2] == k - 1);
                sol.push_back(k);
                reverse(v + 1, v + k + 1);
                assert(v[k - 1] == k - 1 && v[k] == k);
            }
            assert(2 * sol.size() <= 5 * n);
            for (int i = 1; i <= n; i++) {
                assert(v[i] == i);
            }
            cout << sol.size() << "\n";
            for (auto it : sol) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}