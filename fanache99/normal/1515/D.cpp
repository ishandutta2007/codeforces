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

int lefts[1 + MAXN], rights[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, l, r;
        cin >> n >> l >> r;
        for (int i = 1; i <= l; i++) {
            int c;
            cin >> c;
            lefts[c]++;
        }
        for (int i = 1; i <= r; i++) {
            int c;
            cin >> c;
            rights[c]++;
        }
        int ls = 0, rs = 0, lt = 0, rt = 0;
        for (int i = 1; i <= n; i++) {
            int p = min(rights[i], lefts[i]);
            rights[i] -= p;
            lefts[i] -= p;
            ls += lefts[i];
            lt += lefts[i] / 2;
            rs += rights[i];
            rt += rights[i] / 2;
            lefts[i] = rights[i] = 0;
        }
        if (ls > rs) {
            swap(ls, rs);
            swap(lt, rt);
        }
        assert((rs - ls) % 2 == 0);
        int d = (rs - ls) / 2;
        int answer = ls;
        if (d <= rt) {
            answer += d;
        } else {
            answer += rt + 2 * (d - rt);
        }
        cout << answer << "\n";
    }
    return 0;
}