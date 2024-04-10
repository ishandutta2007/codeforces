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

const int MAXN = 1000000;
const long long INF = 1000000000000LL;
const int MOD = 1000000007;

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power & 1) {
            answer = 1LL * answer * base % MOD;
        }
        base = 1LL * base * base % MOD;
        power >>= 1;
    }
    return answer;
}

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

int v[1 + MAXN];

int main() {
    timeBegin();
    //InputReader cin("input.in");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, p;
        cin >> n >> p;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v + 1, v + n + 1);
        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }
        int answer = 1;
        long long have = 1;
        for (int i = n - 1; i >= 1; i--) {
            if (have) {
                int j = v[i + 1] - v[i];
                answer = 1LL * answer * raiseToPower(p, j) % MOD;
                while (have < INF && j) {
                    have *= p;
                    j--;
                }
                if (have > INF) {
                    have = INF;
                }
            }
            if (have >= 1) {
                have--;
                subtractFrom(answer, 1);
            } else {
                answer = have = 1;
            }
        }
        answer = 1LL * answer * raiseToPower(p, v[1]) % MOD;
        cout << answer << "\n";
    }
    //timeDuration();
    return 0;
}