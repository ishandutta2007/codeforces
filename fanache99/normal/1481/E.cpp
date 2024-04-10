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

const int MAXN = 500000;

int v[1 + MAXN];
int total[1 + MAXN], leftmost[1 + MAXN], rightmost[1 + MAXN];
int dp[1 + MAXN], best[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        total[v[i]]++;
        if (leftmost[v[i]] == 0) {
            leftmost[v[i]] = i;
        }
        rightmost[v[i]] = i;
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        best[v[i]] = max(best[v[i]], dp[i - 1]) + 1;
        answer = max(answer, best[v[i]]);
        dp[i] = dp[i - 1];
        if (i == rightmost[v[i]]) {
            dp[i] = max(dp[i], total[v[i]] + dp[leftmost[v[i]] - 1]);
        }
    }
    cout << n - answer << "\n";
    //timeDuration();
    return 0;
}