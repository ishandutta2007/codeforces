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

string s[3];
int f[3][2], which, id[3];

bool compare(int i, int j) {
    return f[i][which] > f[j][which];
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++) {
            cin >> s[i];
            id[i] = i;
            f[i][0] = f[i][1] = 0;
            for (auto ch : s[i]) {
                f[i][ch - '0']++;
            }
        }
        which = 0;
        if ((f[0][0] >= n) + (f[1][0] >= n) + (f[2][0] >= n) < 2) {
            which = 1;
        }
        sort(id, id + 3, compare);
        string a = s[id[0]], b = s[id[1]], ans = "";
        for (int i = 0, j = 0; i < 2 * n || j < 2 * n;) {
            if (i < 2 * n && j < 2 * n && a[i] == b[j]) {
                ans.push_back(a[i]);
                i++;
                j++;
            } else if (i < 2 * n && (j >= 2 * n || a[i] - '0' != which)) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
        assert(ans.size() <= 3 * n);
        cout << ans << "\n";
    }
    //timeDuration();
    return 0;
}