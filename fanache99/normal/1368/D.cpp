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

const int MAXN = 200000;
const int MAXLOG = 20;

int v[1 + MAXN];
pair<int, int> have[MAXLOG];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.txt");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        for (int j = 0; j < MAXLOG; j++) {
            if ((v[i] >> j) & 1) {
                have[j].first++;
            }
        }
    }
    for (int j = 0; j < MAXLOG; j++) {
        have[j].second = j;
    }
    sort(have, have + MAXLOG);
    int before = 0, value = (1 << MAXLOG) - 1;
    long long answer = 0;
    for (int i = 0; i < MAXLOG; i++) {
        answer += 1LL * value * value * (have[i].first - before);
        value ^= (1 << have[i].second);
        before = have[i].first;
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}