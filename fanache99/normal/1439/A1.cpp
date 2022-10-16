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

const int MAXN = 100;

char a[1 + MAXN][1 + MAXN];

void doOp(vector<vector<pair<int, int> > > &answer, int i, int j, int op) {
    vector<pair<int, int> > pos;
    if (op != 0) {
        pos.push_back(make_pair(i, j));
        a[i][j] ^= 1;
    }
    if (op != 1) {
        pos.push_back(make_pair(i, j + 1));
        a[i][j + 1] ^= 1;
    }
    if (op != 2) {
        pos.push_back(make_pair(i + 1, j));
        a[i + 1][j] ^= 1;
    }
    if (op != 3) {
        pos.push_back(make_pair(i + 1, j + 1));
        a[i + 1][j + 1] ^= 1;
    }
    answer.push_back(pos);
}

vector<int> ops[16] = {
        {},
        {1, 2, 3},
        {0, 2, 3},
        {0, 1},
        {0, 1, 3},
        {0, 2},
        {1, 2},
        {3},
        {0, 1, 2},
        {0, 3},
        {1, 3},
        {2},
        {2, 3},
        {1},
        {0},
        {0, 1, 2, 3}
};

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++) {
                a[i][j] -= '0';
            }
        }
        vector<vector<pair<int, int> > > answer;
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j]) {
                    if (j == 1) {
                        doOp(answer, i, j, 1);
                    } else {
                        doOp(answer, i, j - 1, 0);
                    }
                }
            }
        }
        for (int j = 1; j <= m - 2; j++) {
            if (a[n - 1][j]) {
                doOp(answer, n - 1, j, 2);
            }
            if (a[n][j]) {
                doOp(answer, n - 1, j, 0);
            }
        }
        int mask = a[n - 1][m - 1] + 2 * a[n - 1][m] + 4 * a[n][m - 1] + 8 * a[n][m];
        for (auto op : ops[mask]) {
            doOp(answer, n - 1, m - 1, op);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                assert(a[i][j] == 0);
            }
        }
        assert(answer.size() <= m * n);
        cout << answer.size() << "\n";
        for (auto it : answer) {
            for (int i = 0; i < 3; i++) {
                cout << it[i].first << " " << it[i].second << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}