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

const int INF = 1000000000;

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("aparate.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int cold, hot, t;
        cin >> hot >> cold >> t;
        if (t >= hot) {
            cout << "1\n";
        } else if (2 * t <= cold + hot) {
            cout << "2\n";
        } else {
            int left = 1, right = INF, answer = 1;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (1LL * t * (2 * middle - 1) <= 1LL * middle * hot + 1LL * (middle - 1) * cold) {
                    answer = middle;
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
            if (1LL * hot * (1LL * answer * (2 * answer + 1) + 1LL * (answer + 1) * (2 * answer - 1)) +
                1LL * cold * (1LL * (answer - 1) * (2 * answer + 1) + 1LL * answer * (2 * answer - 1)) <=
                2LL * t * (2 * answer - 1) * (2 * answer + 1)) {
                cout << 2 * answer - 1 << "\n";
            } else {
                cout << 2 * answer + 1 << "\n";
            }
        }
    }
    //timeDuration();
    return 0;
}