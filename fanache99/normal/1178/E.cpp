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

const int MAXN = 1000000;

char s[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    cin >> (s + 1);
    int n = strlen(s + 1);
    string t;
    char middle = 0;
    for (int a = 1, b = n; a <= b; a += 2, b -= 2) {
        if (a + 1 < b - 1) {
            int f[3] = {0, 0, 0};
            f[s[a] - 'a']++;
            f[s[a + 1] - 'a']++;
            f[s[b] - 'a']++;
            f[s[b - 1] - 'a']++;
            for (int i = 0; i < 3; i++) {
                if (f[i] >= 2) {
                    t.push_back('a' + i);
                    break;
                }
            }
        } else {
            middle = s[a];
            break;
        }
    }
    assert(t.size() * 2 + (middle != 0) >= n / 2);
    cout << t;
    if (middle != 0) {
        cout << middle;
    }
    reverse(t.begin(), t.end());
    cout << t << "\n";
    //timeDuration();
    return 0;
}