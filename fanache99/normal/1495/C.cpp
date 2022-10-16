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

const int MAXN = 500;
const int MAXM = 500;

char a[1 + MAXN + 1][1 + MAXM + 1];
char aCopy[1 + MAXN + 1][1 + MAXM + 1];
char sol[1 + MAXN + 1][1 + MAXM + 1];
//bool seen[1 + MAXN + 1][1 + MAXM + 1];
int found = 0;

/*bool checkSol(int n, int m) {
    int counter = 0;
    bool started = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (aCopy[i][j] == 'X') {
                assert(sol[i][j] == 'X');
            }
            if (sol[i][j] == 'X') {
                counter++;
                if (!started) {
                    DFS(i, j, n, m);
                }
            }
        }
    }
    assert(found == counter);
}*/

void connect(int n, int m, int i) {
    for (int j = 1; j <= m; j++) {
        if (sol[i - 1][j] == 'X' || sol[i - 2][j] == 'X') {
            sol[i - 1][j] = sol[i - 2][j] = 'X';
            return;
        }
    }
    sol[i - 1][1] = sol[i - 2][1] = 'X';
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
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++) {
                aCopy[i][j] = a[i][j];
                sol[i][j] = a[i][j];
            }
        }
        int r = 1;
        if (n % 3 == 0) {
            r = 2;
        }
        for (int i = 0; 3 * i + r <= n; i++) {
            int x = 3 * i + r;
            for (int j = 1; j <= m; j++) {
                sol[x][j] = 'X';
            }
            if (i > 0) {
                connect(n, m, x);
            }
        }
        //assert(checkSol(n, m));
        for (int i = 1; i <= n; i++) {
            sol[i][m + 1] = 0;
            cout << (sol[i] + 1) << "\n";
        }
    }
    //timeDuration();
    return 0;
}