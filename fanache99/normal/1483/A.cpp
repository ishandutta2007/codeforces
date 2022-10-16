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

int f[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        int limit = (m + 1) / 2;
        vector<vector<int> > day;
        day.resize(m);
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            day[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> day[i][j];
                f[day[i][j]]++;
            }
        }
        int most = 0, which = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] > most) {
                most = f[i];
                which = i;
            }
        }
        if (most <= limit) {
            cout << "YES\n";
            for (int i = 0; i < m; i++) {
                cout << day[i][0] << " ";
            }
            cout << "\n";
        } else {
            int haveTo = 0;
            for (int i = 0; i < m; i++) {
                if (day[i].size() == 1 && day[i][0] == which) {
                    haveTo++;
                }
            }
            if (haveTo > limit) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for (int i = 0; i < m; i++) {
                    if (find(day[i].begin(), day[i].end(), which) == day[i].end() || day[i].size() == 1) {
                        cout << day[i][0] << " ";
                    } else if (most <= limit) {
                        cout << which << " ";
                    } else {
                        most--;
                        if (day[i][0] != which) {
                            cout << day[i][0] << " ";
                        } else {
                            cout << day[i][1] << " ";
                        }
                    }
                }
                cout << "\n";
            }
        }
        for (int i = 1; i <= n; i++) {
            f[i] = 0;
        }
    }
    //timeDuration();
    return 0;
}