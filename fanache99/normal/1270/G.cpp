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

const int MAXN = 1000000;

int v[1 + MAXN], sol[1 + MAXN], k;
int id[1 + MAXN];

void findCycle(int n) {
    for (int i = 1; i <= n; i++) {
        id[i] = 0;
    }
    int node = 1, counter = 0;
    while (id[node] == 0) {
        id[node] = ++counter;
        node = node - v[node];
        assert(node >= 1 && node <= n);
    }
    k = 0;
    for (int i = 1; i <= n; i++) {
        if (id[i] >= id[node]) {
            sol[++k] = i;
        }
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream cout("abbreviation.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        findCycle(n);
        long long sum = 0;
        assert(k > 0);
        cout << k << "\n";
        for (int i = 1; i <= k; i++) {
            int it = sol[i];
            sum += v[it];
            cout << it << " ";
        }
        cout << "\n";
        assert(sum == 0);
    }
    //timeDuration();
    return 0;
}