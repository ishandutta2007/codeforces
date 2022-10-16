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
#include <unordered_set>

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

const int MAXN = 200000;

long long sum[1 + 4 * MAXN];
int small[1 + 4 * MAXN], big[1 + 4 * MAXN], lazy[1 + 4 * MAXN];
int v[1 + MAXN];

void build(int node, int left, int right) {
    lazy[node] = 0;
    if (left == right) {
        sum[node] = small[node] = big[node] = v[left];
        return;
    }
    int middle = (left + right) / 2;
    build(2 * node, left, middle);
    build(2 * node + 1, middle + 1, right);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
    small[node] = small[2 * node + 1];
    big[node] = big[2 * node];
}

void propagate(int node, int left, int right) {
    if (lazy[node]) {
        small[node] = big[node] = lazy[node];
        sum[node] = 1LL * lazy[node] * (right - left + 1);
        if (left != right) {
            lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int limit, int value) {
    propagate(node, left, right);
    if (small[node] >= value) {
        return;
    }
    if (right <= limit && big[node] <= value) {
        lazy[node] = value;
        return;
    }
    int middle = (left + right) / 2;
    update(2 * node, left, middle, limit, value);
    if (middle + 1 <= limit) {
        update(2 * node + 1, middle + 1, right, limit, value);
    }
    propagate(2 * node, left, middle);
    propagate(2 * node + 1, middle + 1, right);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
    small[node] = small[2 * node + 1];
    big[node] = big[2 * node];
}

int getMin(int n) {
    propagate(1, 1, n);
    return small[1];
}

int search1(int node, int left, int right, int limit, int value) {
    propagate(node, left, right);
    if (left == right) {
        return left;
    }
    int middle = (left + right) / 2;
    propagate(2 * node, left, middle);
    if (limit <= middle && small[2 * node] <= value) {
        return search1(2 * node, left, middle, limit, value);
    } else {
        return search1(2 * node + 1, middle + 1, right, limit, value);
    }
}

int answer2, value2;

void search2(int node, int left, int right, int limit) {
    propagate(node, left, right);
    if (left >= limit && sum[node] <= value2) {
        answer2 = right;
        value2 -= sum[node];
        return;
    }
    if (left == right) {
        return;
    }
    int middle = (left + right) / 2;
    if (limit <= middle) {
        search2(2 * node, left, middle, limit);
        if (answer2 == middle) {
            search2(2 * node + 1, middle + 1, right, limit);
        }
    } else {
        search2(2 * node + 1, middle + 1, right, limit);
    }
}

int solve(int x, int y, int n) {
    int answer = 0;
    while (x <= n && getMin(n) <= y) {
        int i = search1(1, 1, n, x, y);
        value2 = y;
        answer2 = i;
        search2(1, 1, n, i);
        int j = answer2;
        y = value2;
        answer += j - i + 1;
        x = j + 1;
    }
    return answer;
}

int main() {
    //timeBegin();
    InputReader cin;
    //ofstream cout("papagali.out");
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(1, 1, n, x, y);
        } else {
            cout << solve(x, y, n) << "\n";
        }
    }
    return 0;
}