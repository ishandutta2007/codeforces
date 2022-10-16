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

const int MAXQ = 1000000;
const int MAXN = 100000;
const int MAXVAL = 7000;

bitset<MAXVAL + 1> v[1 + MAXN];
bitset<MAXVAL + 1> update[1 + MAXVAL], query[1 + MAXVAL];
bool squareFree[1 + MAXVAL];
char answer[1 + MAXQ + 1];

void precompute() {
    for (int i = 1; i <= MAXVAL; i++) {
        squareFree[i] = true;
    }
    for (int x = 2; x <= MAXVAL; x++) {
        for (int i = 1; i * x * x <= MAXVAL; i++) {
            squareFree[i * x * x] = false;
        }
    }
    for (int x = 1; x <= MAXVAL; x++) {
        for (int i = 1; i * x <= MAXVAL; i++) {
            update[i * x][x] = 1;
            if (squareFree[i]) {
                query[x][i * x] = 1;
            }
        }
    }
}

int main() {
    timeBegin();
    InputReader cin;
    //ofstream fout("input.in");
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    precompute();
    int n, q, k = 0;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, val;
            cin >> x >> val;
            v[x] = update[val];
        } else if (type == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x] = v[y] ^ v[z];
        } else if (type == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x] = v[y] & v[z];
        } else {
            int x, val;
            cin >> x >> val;
            answer[++k] = '0' + ((v[x] & query[val]).count() & 1);
        }
    }
    answer[k + 1] = 0;
    cout << (answer + 1) << "\n";
    //timeDuration();
    return 0;
}