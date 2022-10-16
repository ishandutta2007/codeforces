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

const int MAXN = 13845;

int v[1 + MAXN], ans[1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i] % 2 != 0) {
            if (v[i] > 0) {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        } else {
            ans[i] = v[i] / 2;
        }
    }
    if (a.size() > b.size()) {
        swap(a, b);
    }
    for (int i = 0; i < a.size(); i++) {
        ans[a[i]] = floor(0.5 * v[a[i]]);
        ans[b[i]] = ceil(0.5 * v[b[i]]);
    }
    assert((b.size() - a.size()) % 2 == 0);
    for (int i = a.size(); i < b.size(); i += 2) {
        ans[b[i]] = floor(0.5 * v[b[i]]);
        ans[b[i + 1]] = ceil(0.5 * v[b[i + 1]]);
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
        assert(ans[i] == floor(0.5 * v[i]) || (ans[i] == ceil(0.5 * v[i])));
        sum += ans[i];
    }
    assert(sum == 0);
    //timeDuration();
    return 0;
}