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

const int MAXN = 200000;
const int SQRT = 600;

char s[1 + MAXN];
int sum[1 + MAXN];
int f[1 + (MAXN + 1) * SQRT];

long long countForK(int n, int k) {
    long long answer = 0;
    for (int i = 0; i <= n; i++) {
        int x = i - k * sum[i] + k * n;
        answer += f[x];
        f[x]++;
    }
    for (int i = 0 ; i <= n; i++) {
        int x = i - k * sum[i] + k * n;
        f[x]--;
    }
    return answer;
}

long long countRemainder(int x1, int x2, int n, int r) {
    if (x1 > x2 || x2 <= 0) {
        return 0;
    }
    x1 += (r - (x1 % n) + n) % n;
    x2 -= ((x2 % n) - r + n) % n;
    return max(0, (x2 - x1) / n + 1);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + s[i] - '0';
    }
    int limit = sqrt(n);
    long long answer = 0;
    for (int k = 1; k <= limit; k++) {
        answer += countForK(n, k);
    }
    vector<int> ones;
    ones.push_back(0);
    for (int j = 1; j <= n; j++) {
        if (s[j] == '1') {
            ones.push_back(j);
        }
        for (int oneCount = 1; oneCount <= limit && oneCount < ones.size(); oneCount++) {
            int i1 = ones[ones.size() - oneCount - 1] + 1, i2 = min(ones[ones.size() - oneCount], j - limit * oneCount);
            answer += countRemainder(i1, i2, oneCount, (j % oneCount + 1) % oneCount);
        }
    }
    cout << answer << "\n";
    //timeDuration();
    return 0;
}