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

const int MAXN = 300000;
const int MOD = 998244353;

int v[1 + MAXN], sum[1 + MAXN];

void addTo(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void subtractFrom(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int multiply(int a, int b) {
    return 1LL * a * b % MOD;
}

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = multiply(answer, base);
        }
        base = multiply(base, base);
        power >>= 1;
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        addTo(sum[i], v[i]);
    }
    int divide = raiseToPower(n, MOD - 2);
    for (int i = 1; i <= n; i++) {
        int answer = 0;
        for (int j = n - i, k = 1; j >= 1; j -= i, k++) {
            int total = sum[j];
            subtractFrom(total, sum[max(0, j - i)]);
            addTo(answer, multiply(total, k));
        }
        answer = multiply(answer, divide);
        cout << answer << " ";
    }
    //timeDuration();
    return 0;
}