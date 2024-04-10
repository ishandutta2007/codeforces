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

bool know[1 + 4 * MAXN];
int tree[1 + 4 * MAXN];

int ask(int left, int right) {
    cout << "? " << left << " " << right << "\n";
    cout.flush();
    int x;
    cin >> x;
    return (right - left + 1) - x;
}

void answer(int x) {
    cout << "! " << x << "\n";
    cout.flush();
}

void askNode(int node, int left, int right) {
    if (!know[node]) {
        know[node] = true;
        tree[node] = ask(left, right);
    }
}

int query(int node, int left, int right, int k) {
    if (left == right) {
        know[node] = true;
        tree[node] = 0;
        return left;
    }
    int middle = (left + right) / 2, answer;
    askNode(2 * node, left, middle);
    if (k <= tree[2 * node]) {
        answer = query(2 * node, left, middle, k);
    } else {
        answer = query(2 * node + 1, middle + 1, right, k - tree[2 * node]);
    }
    if (know[node]) {
        tree[node]--;
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, tests;
    cin >> n >> tests;
    for (int test = 1; test <= tests; test++) {
        int k;
        cin >> k;
        answer(query(1, 1, n, k));
    }
    return 0;
}