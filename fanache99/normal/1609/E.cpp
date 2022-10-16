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
#include <complex>
#include <unordered_set>
#include <chrono>
#include <random>

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

const int MAXN = 100000;
const int STATES = 6;
const int A = 0;
const int B = 1;
const int C = 2;
const int AB = 3;
const int BC = 4;
const int ABC = 5;

// 0 -> a, 1 -> b, 2 -> c, 3 -> ab, 4 -> bc, 5 -> abc
int tree[1 + 4 * MAXN][STATES];
char s[1 + MAXN];

void leaf(int node, int pos) {
    for (int state = 0; state < STATES; state++) {
        tree[node][state] = 0;
    }
    switch(s[pos]) {
        case 'a' : tree[node][A] = 1; break;
        case 'b' : tree[node][B] = 1; break;
        case 'c' : tree[node][C] = 1; break;
        default: assert(false);
    }
}

void combine(int node) {
    int lSon = 2 * node, rSon = 2 * node + 1;
    tree[node][A] = tree[lSon][A] + tree[rSon][A];
    tree[node][B] = tree[lSon][B] + tree[rSon][B];
    tree[node][C] = tree[lSon][C] + tree[rSon][C];
    tree[node][AB] = min(tree[lSon][A] + tree[rSon][AB], tree[lSon][AB] + tree[rSon][B]);
    tree[node][BC] = min(tree[lSon][B] + tree[rSon][BC], tree[lSon][BC] + tree[rSon][C]);
    tree[node][ABC] = min(min(tree[lSon][A] + tree[rSon][ABC], tree[lSon][ABC] + tree[rSon][C]), tree[lSon][AB] + tree[rSon][BC]);
}

void build(int node, int left, int right) {
    if (left == right) {
        leaf(node, left);
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    combine(node);
}

void update(int node, int left, int right, int pos) {
    if (left == right) {
        assert(left == pos);
        leaf(node, pos);
        return;
    }
    int middle = (left + right) / 2;
    if (pos <= middle) {
        update(2 * node, left, middle, pos);
    } else {
        update(2 * node + 1, middle + 1, right, pos);
    }
    combine(node);
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
//    ofstream cout("answer.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, q;
    cin >> n >> q >> (s + 1);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int pos;
        char ch;
        cin >> pos >> ch;
        s[pos] = ch;
        update(1, 1, n, pos);
        cout << tree[1][ABC] << "\n";
    }
    return 0;
}