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

int v[1 + MAXN], r[1 + MAXN];
vector<pair<int, int> > answer;

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<int> c1, c2;
    for (int c = n, r1 = n + 1, r3 = 0; c >= 1; c--) {
        if (v[c] == 0) {
            continue;
        }
        if (v[c] == 1) {
            r1--;
            r[c] = r1;
            answer.emplace_back(make_pair(r1, c));
            c1.emplace_back(c);
        }
        if (v[c] == 2) {
            if (c1.empty()) {
                cout << "-1\n";
                return 0;
            }
            answer.emplace_back(make_pair(r[c1.back()], c));
            c1.pop_back();
            c2.push_back(c);
        }
        if (v[c] == 3) {
            if (c1.empty() && c2.empty()) {
                cout << "-1\n";
                return 0;
            }
            r1--;
            answer.emplace_back(make_pair(r1, c));
            if (!c2.empty()) {
                answer.emplace_back(make_pair(r1, c2.back()));
                c2.pop_back();
            } else {
                answer.emplace_back(make_pair(r1, c1.back()));
                c1.pop_back();
            }
            c2.push_back(c);
        }
    }
    cout << answer.size() << "\n";
    for (auto it : answer) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}