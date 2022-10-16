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

const int MAXN = 100000;

int a[1 + MAXN], b[1 + MAXN], c[1 + MAXN];
int where[1 + MAXN];
vector<int> redo[1 + MAXN], paint[1 + MAXN];
int answer[1 + MAXN];

void print(int m, int n) {
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
        cout << answer[i] << " ";
        a[answer[i]] = c[i];
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        assert(a[i] == b[i]);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            where[b[i]] = i;
            if (b[i] != a[i]) {
                redo[b[i]].push_back(i);
            }
        }
        int last;
        for (int i = 1; i <= m; i++) {
            cin >> c[i];
            last = c[i];
            paint[c[i]].push_back(i);
        }
        bool bad = false;
        if (where[last] == 0) {
            bad = true;
        } else {
            int temp;
            if (redo[last].empty()) {
                temp = where[last];
            } else {
                temp = redo[last].back();
            }
            for (int i = 1; i <= n; i++) {
                if (paint[i].size() < redo[i].size()) {
                    bad = true;
                    break;
                }
                int j = 0;
                for (auto it : redo[i]) {
                    answer[paint[i][j]] = it;
                    j++;
                }
                for (; j < paint[i].size(); j++) {
                    answer[paint[i][j]] = temp;
                }
            }
        }
        if (bad) {
            cout << "NO\n";
        } else {
            print(m, n);
        }
        for (int i = 1; i <= n; i++) {
            where[i] = 0;
            redo[i].clear();
            paint[i].clear();
        }
    }
    //timeDuration();
    return 0;
}