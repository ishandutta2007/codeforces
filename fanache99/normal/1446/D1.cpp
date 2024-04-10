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

const int MAXN = 200000;
const int MAXVAL = 100;

int f[1 + MAXVAL];
int v[1 + MAXN];
int where[1 + 2 * MAXN];

int solve(int n, int x1, int x2) {
    for (int i = -n; i <= n; i++) {
        where[i + n] = -1;
    }
    int answer = 0, delta = 0;
    where[0 + n] = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == x1) {
            delta++;
        }
        if (v[i] == x2) {
            delta--;
        }
        if (where[delta + n] != -1) {
            answer = max(answer, i - where[delta + n]);
        } else {
            where[delta + n] = i;
        }
    }
    return answer;
}

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, most = 0;
    cin >> n;
    bool distinct = false;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        f[v[i]]++;
        most = max(most, f[v[i]]);
        if (v[i] != v[1]) {
            distinct = true;
        }
    }
    if (!distinct) {
        cout << "0\n";
        return 0;
    }
    int howMany = 0, x = 0;
    for (int i = 1; i <= MAXVAL; i++) {
        if (f[i] == most) {
            x = i;
            howMany++;
        }
    }
    if (howMany > 1) {
        cout << n << "\n";
        return 0;
    }
    int answer = 2;
    for (int i = 1; i <= MAXVAL; i++) {
        if (i != x) {
            answer = max(answer, solve(n, x, i));
        }
    }
    cout << answer << "\n";
    return 0;
}