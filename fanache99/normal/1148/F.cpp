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

const int MAXN = 300000;
const int MAXLOG = 62;

int val[1 + MAXN];
long long mask[1 + MAXN];

int andParity(long long a, long long b) {
    return __builtin_popcountll(a & b) & 1;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> mask[i];
        sum += val[i];
    }
    if (sum < 0) {
        sum *= -1;
        for (int i = 1; i <= n; i++) {
            val[i] *= -1;
        }
    }
    long long answer = 0;
    for (int bit = 0; bit < MAXLOG; bit++) {
        long long odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            if (mask[i] >= (1LL << bit) && mask[i] < (1LL << (bit + 1))) {
                if (andParity(mask[i], answer | (1LL << bit)) == 0) {
                    even += val[i];
                } else {
                    odd += val[i];
                }
            }
        }
        if (even < odd) {
            answer |= 1LL << bit;
        }
    }
    cout << answer << "\n";
    long long newSum = 0;
    for (int i = 1; i <= n; i++) {
        if (andParity(mask[i], answer) == 1) {
            newSum -= val[i];
        } else {
            newSum += val[i];
        }
    }
    assert(newSum < 0);
    //timeDuration();
    return 0;
}