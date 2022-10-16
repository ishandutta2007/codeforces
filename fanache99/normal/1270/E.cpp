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

const int MAXN = 1000;
const int MAXVAL = 1000000;

int x[1 + MAXN], y[1 + MAXN];
vector<int> parity[2][2];

void getParities(int n) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            parity[i][j].clear();
        }
    }
    for (int i = 1; i <= n; i++) {
        parity[x[i] & 1][y[i] & 1].push_back(i);
    }
}

int countParities() {
    int answer = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            answer += !parity[i][j].empty();
        }
    }
    return answer;
}

void divideBy2(int n) {
    for (int i = 1; i <= n; i++) {
        x[i] /= 2;
        y[i] /= 2;
    }
}

void print(int i, int j) {
    for (auto x : parity[i][j]) {
        cout << x << " ";
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        x[i] += MAXVAL;
        y[i] += MAXVAL;
    }
    getParities(n);
    while (countParities() == 1) {
        divideBy2(n);
        getParities(n);
    }
    int even = parity[0][0].size() + parity[1][1].size();
    int odd = parity[0][1].size() + parity[1][0].size();
    if (even != 0 && odd != 0) {
        cout << even << "\n";
        print(0, 0);
        print(1, 1);
    } else if (even != 0) {
        cout << parity[0][0].size() << "\n";
        print(0, 0);
    } else {
        cout << parity[0][1].size() << "\n";
        print(0, 1);
    }
    //timeDuration();
    return 0;
}