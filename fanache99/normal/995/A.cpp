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

const int MAXN = 50;
const int MAXSOL = 20000;

int a[5][1 + MAXN];
pair<int, int> park[1 + 2 * MAXN], where[1 + 2 * MAXN];
pair<int, int> before[5][1 + MAXN], after[5][1 + MAXN];

int myAbs(int x) {
    return x < 0 ? -x : x;
}

bool canMove(pair<int, int> a, pair<int, int> b) {
    return myAbs(a.first - b.first) + myAbs(a.second - b.second) == 1;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream fout("input.in");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                if (i == 1 || i == 4) {
                    park[a[i][j]] = {i, j};
                } else {
                    where[a[i][j]] = {i, j};
                }
            }
        }
    }
    after[2][1] = {3, 1};
    before[3][1] = {2, 1};
    for (int i = 1; i < n; i++) {
        after[2][i + 1] = {2, i};
        before[2][i] = {2, i + 1};
        after[3][i] = {3, i + 1};
        before[3][i + 1] = {3, i};
    }
    after[3][n] = {2, n};
    before[2][n] = {3, n};
    int remaining = k;
    vector<pair<int, pair<int, int> > > sol;
    while (remaining > 0) {
        for (int i = 1; i <= k; i++) {
            if (where[i] != park[i] && canMove(where[i], park[i])) {
                a[where[i].first][where[i].second] = 0;
                sol.push_back({i, park[i]});
                where[i] = park[i];
                remaining--;
            }
        }
        if (remaining == 2 * n) {
            cout << "-1\n";
            return 0;
        }
        if (remaining == 7) {
            k++;
            k--;
        }
        if (remaining > 0) {
            bool found = false;
            for (int i = 2; i <= 3 && !found; i++) {
                for (int j = 1; j <= n && !found; j++) {
                    if (a[i][j] != 0 && a[after[i][j].first][after[i][j].second] == 0) {
                        int x = i, y = j;
                        for (int step = 1; step < 2 * n; step++) {
                            if (a[x][y] != 0) {
                                int x0 = after[x][y].first, y0 = after[x][y].second;
                                assert(a[x0][y0] == 0);
                                sol.push_back({a[x][y], {x0, y0}});
                                a[x0][y0] = a[x][y];
                                a[x][y] = 0;
                                where[a[x0][y0]] = {x0, y0};
                            }
                            int x1 = before[x][y].first, y1 = before[x][y].second;
                            x = x1;
                            y = y1;
                        }
                        found = true;
                    }
                }
            }
        }
    }
    assert(sol.size() <= MAXSOL);
    cout << sol.size() << "\n";
    for (auto it : sol) {
        cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
    }
    //timeDuration();
    return 0;
}