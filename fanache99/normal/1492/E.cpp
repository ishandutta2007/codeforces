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

int n, m;
vector<vector<int> > v;
vector<int> sol;

void printSol() {
    assert(sol.size() == m);
    cout << "Yes\n";
    vector<int> bad(n, 0);
    for (int j = 0; j < m; j++) {
        cout << sol[j] << " ";
        for (int i = 0; i < n; i++) {
            if (v[i][j] != sol[j]) {
                bad[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        assert(bad[i] <= 2);
    }
    exit(0);
}

void noSol() {
    cout << "No\n";
    exit(0);
}

void doTry(int i, vector<int> maybe) {
    if (i == n) {
        printSol();
    }
    int bad = 0;
    for (int j = 0; j < m; j++) {
        bool found = false;
        for (auto p : maybe) {
            if (j == p) {
                found = true;
                break;
            }
        }
        if (!found && v[i][j] != sol[j]) {
            bad++;
        }
    }
    if (bad > 2) {
        return;
    } else if (bad == 2) {
        for (auto p : maybe) {
            sol[p] = v[i][p];
        }
        doTry(i + 1, {});
    } else if (bad == 1) {
        if (maybe.size() == 2) {
            sol[maybe[0]] = v[i][maybe[0]];
            doTry(i + 1, {maybe[1]});
            sol[maybe[1]] = v[i][maybe[1]];
            doTry(i + 1, {maybe[0]});
        } else {
            doTry(i + 1, maybe);
        }
    } else {
        doTry(i + 1, maybe);
    }
}

void tryWith3(int j0, vector<pair<int, vector<int> > > threes, vector<pair<int, vector<int> > > twos) {
    for (auto three : threes) {
        bool found = false;
        for (auto j : three.second) {
            if (j == j0) {
                found = true;
            }
        }
        if (!found) {
            for (auto j : three.second) {
                sol = v[0];
                doTry(0, {j0, j});
            }
            return;
        }
    }
    for (int k = 1; k < threes.size(); k++) {
        if (v[threes[0].first][j0] != v[threes[k].first][j0]) {
            for (auto j : threes[0].second) {
                if (j != j0) {
                    sol = v[0];
                    doTry(0, {j0, j});
                }
            }
            for (auto j : threes[k].second) {
                if (j != j0) {
                    sol = v[0];
                    doTry(0, {j0, j});
                }
            }
            return;
        }
    }
    for (auto two : twos) {
        bool found = false;
        for (auto j : two.second) {
            if (j == j0) {
                found = true;
                break;
            }
        }
        if (!found && v[threes[0].first][j0] != v[two.first][j0]) {
            for (auto j : threes[0].second) {
                if (j != j0) {
                    sol = v[0];
                    doTry(0, {j0, j});
                }
            }
            for (auto j : two.second) {
                if (j != j0) {
                    sol = v[0];
                    doTry(0, {j0, j});
                }
            }
            return;
        }
    }
    sol = v[0];
    sol[j0] = v[threes[0].first][j0];
    printSol();
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v = vector<vector<int> >(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<pair<int, vector<int> > > twos, threes, fours;
    for (int i = 1; i < n; i++) {
        vector<int> bad;
        for (int j = 0; j < m; j++) {
            if (v[i][j] != v[0][j]) {
                bad.push_back(j);
            }
        }
        if (bad.size() > 4) {
            noSol();
        } else if (bad.size() == 4) {
            fours.push_back({i, bad});
        } else if (bad.size() == 3) {
            threes.push_back({i, bad});
        } else if (bad.size() == 2) {
            twos.push_back({i, bad});
        }
    }
    if (!fours.empty()) {
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 4; j++) {
                sol = v[0];
                doTry(0, {fours[0].second[i], fours[0].second[j]});
            }
        }
        noSol();
    } else if (!threes.empty()) {
        for (int i = 0; i < 3; i++) {
            tryWith3(threes[0].second[i], threes, twos);
        }
        noSol();
    } else {
        sol = v[0];
        printSol();
    }
    //timeDuration();
    return 0;
}