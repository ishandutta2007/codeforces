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

using namespace std;

class InputReader {
public:
    InputReader() {
        input_file = stdin;
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

const int MAXN = 1000000;
const int MAXLOG = 20;

int fenwick[1 + MAXN];

void update(int x, int n, int add) {
    //cout << x << " " << add << "\n";
    for (; x <= n; x += (x & -x))
        fenwick[x] += add;
}

int query(int x, int n) {
    int answer = 0, sum = 0;
    for (int i = MAXLOG; i >= 0; i--)
        if (answer + (1 << i) <= n && sum + fenwick[answer + (1 << i)] < x) {
            answer += 1 << i;
            sum += fenwick[answer];
        }
    return answer + 1;
}

int main() {
    InputReader cin;
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(x, n, 1);
    }
    int total = n;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            update(x, n, 1);
            total++;
        }
        else {
            update(query(-x, n), n, -1);
            total--;
        }
    }
    if (total)
        cout << query(1, n) << "\n";
    else
        cout << "0\n";
    return 0;
}