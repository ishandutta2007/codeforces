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

const int MAXN = 300000;
const int MAXLOG = 32;

pair<int, int> v[1 + MAXN];
long long total[MAXLOG][2];

vector<int> solve(int l, int r, int bit) {
    vector<int> answer;
    if (l <= r) {
        if (bit == -1) {
            for (int i = l; i <= r; i++) {
                answer.emplace_back(v[i].second);
            }
        } else {
            int m = l;
            while (m <= r && ((v[m].first >> bit) & 1) == 0) {
                m++;
            }
            vector<int> v0 = solve(l, m - 1, bit - 1), v1 = solve(m, r, bit - 1);
            long long current = 0;
            for (int i = 0, j = 0; i < v0.size() || j < v1.size();) {
                if (i < v0.size() && (j == v1.size() || v0[i] < v1[j])) {
                    current += j;
                    answer.emplace_back(v0[i]);
                    i++;
                } else {
                    answer.emplace_back(v1[j]);
                    j++;
                }
            }
            total[bit][0] += current;
            total[bit][1] += 1LL * v0.size() * v1.size() - current;
        }
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    solve(1, n, MAXLOG - 1);
    long long answer = 0;
    int x = 0;
    for (int i = 0; i < MAXLOG; i++) {
        if (total[i][1] < total[i][0]) {
            x |= 1 << i;
        }
        answer += min(total[i][1], total[i][0]);
    }
    cout << answer << " " << x << "\n";
    return 0;
}