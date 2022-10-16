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

const int MAXN = 500000;

char s[1 + MAXN];

long long solveSlow(int n) {
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, best = 0;
        for (int j = i; j <= n; j++) {
            if (s[j] == '1') {
                l++;
            } else {
                l = 0;
            }
            best = max(best, l);
            answer += best;
        }
    }
    return answer;
}

int st[1 + MAXN], l[1 + MAXN + 1];
long long sum[1 + MAXN];

long long solveFast(int n) {
    long long answer = 0;
    int top = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1') {
            l[i] = 1 + l[i + 1];
        } else {
            l[i] = 0;
        }
        if (l[i] > 0) {
            while (top > 0 && l[i] >= l[st[top]]) {
                top--;
            }
            top++;
            st[top] = i;
            if (top == 1) {
                sum[top] = 1LL * l[i] * (l[i] + 1) / 2 + 1LL * l[i] * (n - (i + l[i] - 1));
            } else {
                sum[top] = sum[top - 1] + 1LL * l[i] * (st[top - 1] - st[top]);
            }
        }
        answer += sum[top];
    }
    return answer;
}

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    /*srand(time(0));
    while (true) {
        int n = 1000;
        for (int i = 1; i <= n; i++) {
            if (rand() % 5 == 0) {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
        int slow = solveSlow(n), fast = solveFast(n);
        if (slow != fast) {
            cout << "Wrong: " << n << " " << slow << " " << fast << "\n" << (s + 1) << "\n";
            while (1) {}
        } else {
            cout << "Ok\n";
        }
    }*/
    int n;
    cin >> n >> (s + 1);
    cout << solveFast(n) << "\n";
    return 0;
}