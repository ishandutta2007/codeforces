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
#include <unordered_map>

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

const int MAXN = 50;

bool q[2][1 + MAXN][1 + MAXN][1 + MAXN][1 + MAXN];
int a[1 + MAXN][1 + MAXN];

bool ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void compute(int id, int n) {
    for (int x1 = n; x1 >= 1; x1--) {
        for (int y1 = n; y1 >= 1; y1--) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    if (x2 - x1 + y2 - y1 <= 1) {
                        if (x1 == x2 && y1 == y2) {
                            q[id][x1][y1][x2][y2] = false;
                        } else {
                            q[id][x1][y1][x2][y2] = (a[x1][y1] == a[x2][y2]);
                        }
                    } else {
                        if (a[x1][y1] != a[x2][y2]) {
                            q[id][x1][y1][x2][y2] = false;
                        } else {
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 2; j++) {
                                    if (x1 + i <= x2 && y1 + 1 - i <= y2 && x2 - j >= x1 && y2 - 1 + j >= y1) {
                                        q[id][x1][y1][x2][y2] |= q[id][x1 + i][y1 + 1 - i][x2 - j][y2 - 1 + j];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    a[1][1] = 1;
    a[1][2] = 0;
    for (int j = 3; j <= n; j++) {
        a[1][j] = a[1][j - 2] ^ ask(1, j - 2, 1, j) ^ 1;
    }
    for (int j = 2; j <= n; j++) {
        a[2][j] = a[1][j - 1] ^ ask(1, j - 1, 2, j) ^ 1;
    }
    a[2][1] = a[2][3] ^ ask(2, 1, 2, 3) ^ 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 2][j] ^ ask(i - 2, j, i, j) ^ 1;
        }
    }
    compute(0, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 1) {
                a[i][j] ^= 1;
            }
        }
    }
    compute(1, n);
    bool found = false;
    for (int x1 = 1; x1 <= n && !found; x1++) {
        for (int y1 = 1; y1 <= n && !found; y1++) {
            for (int x2 = x1; x2 <= n && !found; x2++) {
                for (int y2 = y1; y2 <= n && !found; y2++) {
                    if (x2 - x1 + y2 - y1 >= 2 && q[0][x1][y1][x2][y2] != q[1][x1][y1][x2][y2]) {
                        found = true;
                        int x = ask(x1, y1, x2, y2);
                        if (x == q[0][x1][y1][x2][y2]) {
                            for (int i = 1; i <= n; i++) {
                                for (int j = 1; j <= n; j++) {
                                    if ((i + j) % 2 == 1) {
                                        a[i][j] ^= 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "!\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    cout.flush();
    //timeDuration();
    return 0;
}