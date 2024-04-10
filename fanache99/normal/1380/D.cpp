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

int a[1 + MAXN + 1], b[1 + MAXN + 1];

long long eliminate(int l, int r, int x, int k, int y) {
    int n = r - l + 1;
    if (n == 0) {
        return 0;
    }
    int m = 0;
    for (int i = l; i <= r; i++) {
        m = max(m, a[i]);
    }
    if (m > max(a[l - 1], a[r + 1])) {
        if (n < k) {
            cout << "-1\n";
            exit(0);
        }
        long long answer = 1LL * (n % k) * y;
        if (x <= 1LL * k * y) {
            answer += 1LL * (n / k) * x;
        } else {
            answer += 1LL * (n / k - 1) * k * y + x;
        }
        return answer;
    } else {
        long long answer = 1LL * (n % k) * y;
        if (x <= 1LL * k * y) {
            answer += 1LL * (n / k) * x;
        } else {
            answer += 1LL * (n / k) * k * y;
        }
        return answer;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, m, x, k, y;
    cin >> n >> m >> x >> k >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    long long answer = 0;
    int j = 1;
    for (int i = 1; i <= m; i++) {
        int jPrev = j;
        while (j <= n && a[j] != b[i]) {
            j++;
        }
        if (j > n) {
            cout << "-1\n";
            return 0;
        }
        answer += eliminate(jPrev, j - 1, x, k, y);
        j++;
    }
    answer += eliminate(j, n, x, k, y);
    cout << answer << "\n";
    //timeDuration();
    return 0;
}