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

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        if (k == 0) {
            long long sum = 0;
            for (int i = 0; i < n / 2; i++) {
                cout << i << " " << ((n - 1) ^ i) << "\n";
                sum += (i & ((n - 1) ^ i));
            }
            assert(sum == k);
        } else if (k == n - 1) {
            if (n == 4) {
                cout << "-1\n";
            } else {
                long long sum = ((n - 2) & (n - 1)) + (1 & 3) + ((n - 4) & 0);
                cout << n - 2 << " " << n - 1 << "\n";
                cout << 1 << " " << 3 << "\n";
                cout << n - 4 << " " << 0 << "\n";
                for (int i = 0; i < n / 2; i++) {
                    if (i != 0 && i != 1 && i != 3 && i != n - 4 && i != n - 2 && i != n - 1) {
                        cout << i << " " << ((n - 1) ^ i) << "\n";
                        sum += (i & ((n - 1) ^ i));
                    }
                }
                assert(sum == k);
            }
        } else {
            long long sum = (k & (n - 1)) + (0 & (k ^ (n - 1)));
            cout << k << " " << n - 1 << "\n";
            cout << 0 << " " << (k ^ (n - 1)) << "\n";
            for (int i = 0; i < n / 2; i++) {
                if (i != 0 && i != k && i != (k ^ (n - 1))) {
                    cout << i << " " << ((n - 1) ^ i) << "\n";
                    sum += (i & ((n - 1) ^ i));
                }
            }
            assert(sum == k);
        }
    }
    return 0;
}