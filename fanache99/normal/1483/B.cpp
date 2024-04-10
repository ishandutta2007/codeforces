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

int myGcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int v[MAXN];
int toRight[MAXN], toLeft[MAXN];
set<int> active;

void eliminate(int x) {
    int l = toLeft[x], r = toRight[x];
    toRight[l] = r;
    toLeft[r] = l;
    if (myGcd(v[l], v[x]) == 1) {
        active.erase(l);
    }
    if (myGcd(v[x], v[r]) == 1) {
        active.erase(x);
    }
    if (myGcd(v[l], v[r]) == 1) {
        active.insert(l);
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("abbreviation.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            toLeft[i] = (i - 1 + n) % n;
            toRight[i] = (i + 1) % n;
        }
        active.clear();
        for (int i = 0; i < n; i++) {
            if (myGcd(v[i], v[toRight[i]]) == 1) {
                active.insert(i);
            }
        }
        int last = n - 1, remaining = n;
        vector<int> sol;
        while (remaining > 0 && !active.empty()) {
            auto it = active.upper_bound(last);
            if (it == active.end()) {
                it = active.begin();
            }
            int x = toRight[*it];
            eliminate(x);
            sol.push_back(x);
            remaining--;
            last = x;
        }
        cout << sol.size() << " ";
        for (auto it : sol) {
            cout << it + 1 << " ";
        }
        cout << "\n";
    }
    //timeDuration();
    return 0;
}