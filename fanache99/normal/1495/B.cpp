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
#include <unordered_map>

using namespace std;

clock_t timeStart, timecinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timecinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timecinish - timeStart) / double(CLOCKS_PER_SEC);
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

const int MAXN = 100000;

int p[1 + MAXN + 1];
int decRight[1 + MAXN + 1], maxDecRight[1 + MAXN + 1];
int incRight[1 + MAXN + 1], maxIncRight[1 + MAXN + 1];
int decLeft[1 + MAXN + 1], maxDecLeft[1 + MAXN + 1];
int incLeft[1 + MAXN + 1], maxIncLeft[1 + MAXN + 1];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    p[0] = p[n + 1] = n + 1;
    decLeft[1] = incLeft[1] = maxDecLeft[1] = maxIncLeft[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i] < p[i - 1]) {
            incLeft[i] = incLeft[i - 1] + 1;
            decLeft[i] = 1;
        } else {
            decLeft[i] = decLeft[i - 1] + 1;
            incLeft[i] = 1;
        }
        maxDecLeft[i] = max(maxDecLeft[i - 1], decLeft[i]);
        maxIncLeft[i] = max(maxIncLeft[i - 1], incLeft[i]);
    }
    decRight[n] = incRight[n] = maxDecRight[n] = maxIncRight[n] = 1;
    for (int i = n - 1; i >= 1; i--) {
        if (p[i] < p[i + 1]) {
            incRight[i] = incRight[i + 1] + 1;
            decRight[i] = 1;
        } else {
            decRight[i] = decRight[i + 1] + 1;
            incRight[i] = 1;
        }
        maxDecRight[i] = max(maxDecRight[i + 1], decRight[i]);
        maxIncRight[i] = max(maxIncRight[i + 1], incRight[i]);
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int a = decLeft[i], b = decRight[i];
        if (a == b && a % 2 == 1 && a != 1) {
            int best = max(max(maxDecLeft[i - a + 1], maxIncLeft[i - a + 1]), max(maxDecRight[i + b - 1], maxIncRight[i + b - 1]));
            if (a > best) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}