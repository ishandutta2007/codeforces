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
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXK = 18;

int winners[1 << (MAXK + 3)];
char s[1 << (MAXK + 3)];

void merge(int node) {
    winners[node] = 0;
    if (s[node] != '0') {
        winners[node] += winners[2 * node];
    }
    if (s[node] != '1') {
        winners[node] += winners[2 * node + 1];
    }
}

void buildTree(int node, int left, int right) {
    if (left == right) {
        winners[node] = 1;
    } else {
        int middle = (left + right) / 2;
        buildTree(2 * node, left, middle);
        buildTree(2 * node + 1, middle + 1, right);
        merge(node);
    }
}

void update(int node) {
    while (node != 0) {
        merge(node);
        node /= 2;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int k, q;
    cin >> k >> (s + 1) >> q;
    int n = 1 << k;
    reverse(s + 1, s + n);
    buildTree(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        x = (n - 1) - x + 1;
        cin >> s[x];
        update(x);
        cout << winners[1] << "\n";
    }
    return 0;
}