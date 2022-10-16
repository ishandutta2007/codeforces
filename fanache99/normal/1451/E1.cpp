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
#include <bitset>
#include <unordered_set>

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

const int MAXN = 1 << 16;

int query(string s, int i, int j) {
    cout << s << " " << i << " " << j << "\n";
    cout.flush();
    int answer;
    cin >> answer;
    return answer;
}

int power2(int x) {
    int answer = 0;
    while (x) {
        answer++;
        x /= 2;
    }
    return answer;
}

int v[1 + MAXN];
int xor1[1 + MAXN];
int where[MAXN];

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    int b = power2(n);
    bool found = false;
    int x, y;
    for (int i = 2; i <= n; i++) {
        xor1[i] = query("XOR", 1, i);
        if (where[xor1[i]]) {
            found = true;
            x = where[xor1[i]];
            y = i;
        } else {
            where[xor1[i]] = i;
        }
    }
    if (found) {
        v[1] = query("AND", x, y) ^ xor1[x];
    } else if (where[0]) {
        v[1] = query("AND", 1, where[0]);
    } else {
        v[1] = (1 & query("AND", 1, where[n - 2])) | ((n - 2) & query("AND", 1, where[1]));
    }
    for (int i = 2; i <= n; i++) {
        v[i] = v[1] ^ xor1[i];
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << v[i];
    }
    cout << "\n";
    cout.flush();
    return 0;
}