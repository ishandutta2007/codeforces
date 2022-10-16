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

const int MAXN = 100000;

long long split(int x, int n) {
    return 1LL * n * (x / n) * (x / n) + 1LL * (x % n) * (2 * (x / n) + 1);
}

struct Carrot {
    long long delta;
    int x;
    int k;

    bool operator < (const Carrot &other) const {
        return delta < other.delta;
    }
};

priority_queue<Carrot> pq;

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n, k;
    cin >> n >> k;
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        answer += 1LL * x * x;
        if (x > 1) {
            pq.push({split(x, 1) - split(x, 2), x, 1});
        }
    }
    for (int i = n + 1; i <= k; i++) {
        Carrot c = pq.top();
        pq.pop();
        answer -= c.delta;
        if (c.x > c.k) {
            c.k++;
            c.delta = split(c.x, c.k) - split(c.x, c.k + 1);
            pq.push(c);
        }
    }
    cout << answer << "\n";
    return 0;
}