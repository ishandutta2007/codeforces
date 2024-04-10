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

class InputReader {
public:
    InputReader() {}
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

const int MAXN = 300;

char a[1 + MAXN][1 + MAXN], answer[1 + MAXN][1 + MAXN];
bool found;

void makeTry(int n, int total, int x, int o) {
    if (found) {
        return;
    }
    int changed = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int r = (i + j) % 3;
            if (a[i][j] == '.' || (r != x && r != o)) {
                answer[i][j] = a[i][j];
            } else {
                if (r == x) {
                    answer[i][j] = 'X';
                    if (a[i][j] != 'X') {
                        changed++;
                    }
                } else {
                    answer[i][j] = 'O';
                    if (a[i][j] != 'O') {
                        changed++;
                    }
                }
            }
        }
    }
    if (3 * changed <= total) {
        found = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, total = 0;
        cin >> n;
        memset(answer, 0, sizeof(answer));
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= n; j++) {
                total += (a[i][j] != '.');
            }
        }
        found = false;
        makeTry(n, total, 0, 1);
        makeTry(n, total, 0, 2);
        makeTry(n, total, 1, 2);
        makeTry(n, total, 1, 0);
        makeTry(n, total, 2, 0);
        makeTry(n, total, 2, 1);
        assert(found == true);
        for (int i = 1; i <= n; i++) {
            cout << answer[i] + 1 << "\n";
        }
    }
    return 0;
}