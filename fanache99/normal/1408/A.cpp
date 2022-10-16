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
    inline InputReader &operator >>(long long &n) {
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

const int MAXN = 100;

int v[3][1 + MAXN];
int answer[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int j = 0; j < 3; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> v[j][i];
            }
        }
        answer[1] = v[0][1];
        for (int i = 2; i < n; i++) {
            if (v[0][i] != answer[i - 1]) {
                answer[i] = v[0][i];
            } else {
                answer[i] = v[1][i];
            }
        }
        if (v[0][n] != answer[n - 1] && v[0][n] != answer[1]) {
            answer[n] = v[0][n];
        } else if (v[1][n] != answer[n - 1] && v[1][n] != answer[1]) {
            answer[n] = v[1][n];
        } else {
            answer[n] = v[2][n];
        }
        for (int i = 1; i <= n; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}