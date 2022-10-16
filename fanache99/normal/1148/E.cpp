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

const int MAXN = 300000;

struct Stone {
    int x;
    int id;

    bool operator < (const Stone &other) const {
        return x < other.x;
    }
};

Stone s[1 + MAXN];
int t[1 + MAXN], cs[1 + MAXN];
Stone st[1 + MAXN];

struct Op {
    int i;
    int j;
    int d;
};

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    long long sSum = 0, tSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].x;
        cs[i] = s[i].x;
        sSum += s[i].x;
        s[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        tSum += t[i];
    }
    if (sSum != tSum) {
        cout << "NO\n";
    } else {
        sort(s + 1, s + n + 1);
        sort(t + 1, t + n + 1);
        vector<Op> sol;
        for (int i = 1, top = 0; i <= n; i++) {
            int d = t[i] - s[i].x;
            if (d > 0) {
                top++;
                st[top] = {d, s[i].id};
            } else {
                d = -d;
                while (d > 0) {
                    if (top == 0) {
                        cout << "NO\n";
                        return 0;
                    }
                    int d0 = min(d, st[top].x);
                    sol.push_back({st[top].id, s[i].id, d0});
                    d -= d0;
                    st[top].x -= d0;
                    if (st[top].x == 0) {
                        top--;
                    }
                }
            }
        }
        assert(sol.size() <= 5 * n);
        cout << "YES\n" << sol.size() << "\n";
        for (auto it : sol) {
            cout << it.i << " " << it.j << " " << it.d << "\n";
            assert(it.i >= 1 && it.i <= n && it.j >= 1 && it.j <= n && it.i != it.j);
            int a = it.i, b = it.j, d = it.d;
            if (cs[a] > cs[b]) {
                swap(a, b);
            }
            assert(cs[a] + d <= cs[b] - d);
            cs[a] += d;
            cs[b] -= d;
        }
        sort(cs + 1, cs + n + 1);
        for (int i = 1; i <= n; i++) {
            assert(t[i] == cs[i]);
        }
    }
    //timeDuration();
    return 0;
}