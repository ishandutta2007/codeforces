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

const int SIGMA = 26;
const int MAXN = 100000;

char s[1 + MAXN], sol[1 + MAXN + 1];
int f[SIGMA];

void init() {
    for (int i = 0; i < SIGMA; i++) {
        f[i] = 0;
    }
}

bool ok(int k) {
    for (int i = 0; i < SIGMA; i++) {
        if (f[i] % k != 0) {
            return false;
        }
    }
    return true;
}

bool trySol(int n, int k, int p, char ch) {
    f[ch - 'a']++;
    int limit = 0;
    for (int i = 0; i < SIGMA; i++) {
        if (f[i] % k != 0) {
            limit += k - f[i] % k;
        }
    }
    if (limit > n - p) {
        f[ch - 'a']--;
        return false;
    } else {
        for (int i = 1; i < p; i++) {
            sol[i] = s[i];
        }
        sol[p] = ch;
        for (int i = p + 1; i <= n - limit; i++) {
            sol[i] = 'a';
        }
        for (int i = n - limit + 1, j = 0; i <= n; i++) {
            while (f[j] % k == 0) {
                j++;
            }
            sol[i] = 'a' + j;
            f[j]++;
        }
        sol[n + 1] = 0;
        return true;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k >> (s + 1);
        if (n % k != 0) {
            cout << "-1\n";
        } else {
            init();
            for (int i = 1; i <= n; i++) {
                f[s[i] - 'a']++;
            }
            if (ok(k)) {
                for (int i = 1; i <= n; i++) {
                    sol[i] = s[i];
                }
                sol[n + 1] = 0;
                cout << (sol + 1) << "\n";
            } else {
                bool found = false;
                for (int i = n; i >= 1 && !found; i--) {
                    f[s[i] - 'a']--;
                    for (char ch = s[i] + 1; ch <= 'z' && !found; ch++) {
                        found |= trySol(n, k, i, ch);
                    }
                }
                cout << (sol + 1) << "\n";
            }
        }
    }
    //timeDuration();
    return 0;
}