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

const int MAXN = 1000;

pair<int, int> v[1 + MAXN];
char answer[1 + MAXN + 1][1 + MAXN + 1];
int myId[1 + MAXN + 1], f[1 + MAXN + 1], newmyId[1 + MAXN + 1];
int temp[1 + 2 * (MAXN + 1)];

void normalize(int r) {
    for (int i = 1; i <= 2 * r; i++) {
        temp[i] = 0;
    }
    int m = 0;
    for (int i = 1; i <= r; i++) {
        if (temp[myId[i]] == 0) {
            temp[myId[i]] = ++m;
        }
        myId[i] = temp[myId[i]];
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.i`n");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            answer[i][j] = '0';
        }
    }
    sort(v + 1, v + n + 1);
    reverse(v + 1, v + n + 1);
    int r;
    if (v[1].first == 1) {
        r = 1;
        for (int i = 1; i <= n; i++) {
            answer[1][i] = '1';
        }
    } else {
        if (v[1].first == v[2].first) {
            r = v[1].first + 1;
            answer[1][v[2].second] = '1';
            myId[1] = 1;
            for (int i = 2; i <= r - 1; i++) {
                answer[i][v[1].second] = answer[i][v[2].second] = '1';
                myId[i] = 2;
            }
            myId[r] = 3;
            answer[r][v[1].second] = '1';
        } else {
            r = v[1].first;
            for (int i = 1; i <= v[2].first; i++) {
                answer[i][v[1].second] = answer[i][v[2].second] = '1';
                myId[i] = 1;
            }
            for (int i = v[2].first + 1; i <= r; i++) {
                answer[i][v[1].second] = '1';
                myId[i] = 2;
            }
        }
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= r; j++) {
                f[j] = 0;
                newmyId[j] = 0;
            }
            int m = 0;
            for (int j = 1; j <= r; j++) {
                f[myId[j]]++;
                m = max(m, myId[j]);
            }
            int x, smallest = n + 1;
            for (int j = 1; j <= m; j++) {
                if (f[j] >= 2 && f[j] < smallest) {
                    smallest = f[j];
                    x = j;
                }
            }
            int k, l;
            if (smallest == n + 1) {
                x = 0;
                k = 0;
                l = v[i].first;
            } else {
                k = min(f[x] - 1, v[i].first);
                l = v[i].first - k;
            }
            for (int j = 1; j <= r; j++) {
                if ((myId[j] == x && k > 0) || (myId[j] != x && l > 0)) {
                    if (myId[j] == x) {
                        k--;
                    } else {
                        l--;
                    }
                    if (newmyId[myId[j]] == 0) {
                        newmyId[myId[j]] = ++m;
                    }
                    myId[j] = newmyId[myId[j]];
                    answer[j][v[i].second] = '1';
                }
            }
            normalize(r);
            assert(k == 0 && l == 0);
        }
    }
    cout << r << "\n";
    for (int i = 1; i <= r; i++) {
        answer[i][n + 1] = 0;
        cout << (answer[i] + 1) << "\n";
    }
    //timeDuration();
    return 0;
}