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

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while(buffer[cursor] < '0' || buffer[cursor] > '9') {
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
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

const int DIGITS = 10;
const int MAXN = 2000;
const int MAXK = 2000;
const int STICKS = 7;

string digit[DIGITS] = {
        "1110111", // 0
        "0010010", // 1
        "1011101", // 2
        "1011011", // 3
        "0111010", // 4
        "1101011", // 5
        "1101111", // 6
        "1010010", // 7
        "1111111", // 8
        "1111011"  // 9
};

string s[1 + MAXN];
int need[1 + MAXN][DIGITS];
bool can[1 + MAXN + 1][1 + MAXK];

int transform(string &a, string &b) {
    int answer = 0;
    for (int i = 0; i < STICKS; i++) {
        if (a[i] == '1' && b[i] == '0')
            return MAXK + 1;
        if (a[i] == '0' && b[i] == '1')
            answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.in");
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < DIGITS; j++)
            need[i][j] = transform(s[i], digit[j]);
    }
    can[n + 1][0] = true;
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= k; j++)
            for (int c = 0; c < DIGITS && !can[i][j]; c++)
                if (need[i][c] <= j)
                    can[i][j] |= can[i + 1][j - need[i][c]];
    if (!can[1][k])
        cout << "-1\n";
    else {
        for (int i = 1, j = k; i <= n; i++)
            for (int c = DIGITS - 1; c >= 0; c--)
                if (need[i][c] <= j && can[i + 1][j - need[i][c]]) {
                    cout << (char)('0' + c);
                    j -= need[i][c];
                    break;
                }
        cout << "\n";
    }
    return 0;
}