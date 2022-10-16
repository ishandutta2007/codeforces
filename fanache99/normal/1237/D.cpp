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

const int MAXN = 100000;
const int INF = 1000000000;

int v[1 + 2 * MAXN];
int stMin[1 + 2 * MAXN], stMax[1 + 2 * MAXN], answer[1 + MAXN];

int searchBad(int n, int x) {
    int left = 1, right = n, answer = 0;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (2 * v[stMin[middle]] < x) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int n, biggest = 0, smallest = INF;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
        biggest = max(biggest, v[i]);
        smallest = min(smallest, v[i]);
    }
    if (smallest * 2 >= biggest) {
        for (int i = 1; i <= n; i++) {
            cout << "-1 ";
        }
    } else {
        int biggestBad = 0, biggestPos;
        for (int i = 1; i <= n; i++) {
            if (v[i] == biggest) {
                biggestPos = i;
            }
        }
        while (2 * v[biggestPos + biggestBad] >= v[biggestPos]) {
            biggestBad++;
        }
        biggestPos += n;
        answer[(biggestPos - 1) % n + 1] = biggestBad;
        int topMin = 1, topMax = 1;
        stMin[1] = stMax[1] = biggestPos;
        for (int i = biggestPos - 1; i > biggestPos - n; i--) {
            while (topMin > 0 && v[stMin[topMin]] >= v[i]) {
                topMin--;
            }
            while (topMax > 0 && v[stMax[topMax]] < v[i]) {
                topMax--;
            }
            int bad = searchBad(topMin, v[i]);
            if (bad != 0 && stMin[bad] < stMax[topMax]) {
                answer[(i - 1) % n + 1] = stMin[bad] - i;
            } else {
                answer[(i - 1) % n + 1] = stMax[topMax] - i + answer[(stMax[topMax] - 1) % n + 1];
            }
            topMin++;
            stMin[topMin] = i;
            topMax++;
            stMax[topMax] = i;
        }
        for (int i = 2 * n; i >= 1; i--) {
        }
        for (int i = 1; i <= n; i++) {
            cout << answer[i] << " ";
        }
    }
    //timeDuration();
    return 0;
}