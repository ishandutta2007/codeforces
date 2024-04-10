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

const int MAXN = 200000;

int p[1 + 2 * MAXN], v[1 + MAXN];
int toRight[1 + MAXN], toLeft[1 + MAXN];
int st[1 + MAXN], d[1 + MAXN], dMax[1 + MAXN];

void getDepths(int n, int depth[]) {
    int top = 1;
    st[1] = 1;
    d[1] = 1;
    dMax[1] = 1;
    depth[0] = 1;
    for (int i = 1; i < n; i++) {
        int current = 0;
        while (st[top] > v[i]) {
            current = max(current, d[top]) + 1;
            top--;
        }
        current = max(current, 1);
        top++;
        st[top] = v[i];
        d[top] = current;
        dMax[top] = max(dMax[top - 1], d[top] + top - 1);
        depth[i] = dMax[top];
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    int n, one;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i + n] = p[i];
        if (p[i] == 1) {
            one = i;
        }
    }
    for (int i = one + 1; i < one + n; i++) {
        v[i - one] = p[i];
    }
    getDepths(n, toRight);
    reverse(v + 1, v + n);
    getDepths(n, toLeft);
    int best = n + 1, shift;
    for (int i = 0, a = one - 1, b = n - one; i < n; i++) {
        if (max(toLeft[a], toRight[b]) < best) {
            best = max(toLeft[a], toRight[b]);
            shift = i;
        }
        a = (a - 1 + n) % n;
        b = (b + 1) % n;
    }
    cout << best << " " << shift << "\n";
    //timeDuration();
    return 0;
}