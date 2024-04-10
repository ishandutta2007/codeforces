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

const int MAXN = 2000;

int v[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    int n;
    cin >> n;
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        f[v[i]]++;
    }
    int answer = n, bad = 0;
    for (auto it : f) {
        if (it.second > 1) {
            bad++;
        }
    }
    if (bad == 0) {
        cout << "0\n";
        return 0;
    }
    for (int l = 1; l <= n; l++) {
        map<int, int> cf = f;
        int remaining = bad;
        for (int r = l; r <= n; r++) {
            cf[v[r]]--;
            if (cf[v[r]] == 1) {
                remaining--;
                if (remaining == 0) {
                    answer = min(answer, r - l + 1);
                    break;
                }
            }
        }
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}