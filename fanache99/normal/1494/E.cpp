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

clock_t timeStart, timecinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timecinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timecinish - timeStart) / double(CLOCKS_PER_SEC);
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

map<pair<int, int>, char> edge;

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int doubleEdges = 0, sameEdges = 0;
    for (int i = 1; i <= m; i++) {
        char type;
        cin >> type;
        if (type == '+') {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (edge.find({b, a}) != edge.end()) {
                doubleEdges++;
                if (edge[{b, a}] == c) {
                    sameEdges++;
                }
            }
            edge[{a, b}] = c;
        } else if (type == '-') {
            int a, b;
            cin >> a >> b;
            if (edge.find({b, a}) != edge.end()) {
                doubleEdges--;
                if (edge[{b, a}] == edge[{a, b}]) {
                    sameEdges--;
                }
            }
            edge.erase({a, b});
        } else {
            int k;
            cin >> k;
            if (k % 2 == 0) {
                if (sameEdges > 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            } else {
                if (doubleEdges > 0) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    //timeDuration();
    return 0;
}