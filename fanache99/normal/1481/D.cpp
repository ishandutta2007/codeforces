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

char edge[1 + MAXN][1 + MAXN];

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("greutati.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (edge[i] + 1);
        }
        if (m % 2 == 1) {
            cout << "YES\n";
            for (int k = 1, node = 1; k <= m + 1; k++) {
                cout << node << " ";
                node = 3 - node;
            }
            cout << "\n";
        } else {
            bool found = false;
            for (int i = 1; i <= n && !found; i++) {
                for (int j = i + 1; j <= n && !found; j++) {
                    if (edge[i][j] == edge[j][i]) {
                        found = true;
                        cout << "YES\n";
                        for (int k = 1, node = i; k <= m + 1; k++) {
                            cout << node << " ";
                            node = i + j - node;
                        }
                        cout << "\n";
                    }
                }
            }
            if (!found) {
                if (n == 2) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    if (edge[1][2] == edge[2][3] && edge[2][3] == edge[3][1]) {
                        for (int k = 1, node = 1; k <= m + 1; k++) {
                            cout << node << " ";
                            node = node % 3 + 1;
                        }
                        cout << "\n";
                    } else {
                        int root;
                        if (edge[2][1] != edge[2][3]) {
                            root = 2;
                        } else if (edge[1][3] != edge[1][2]) {
                            root = 1;
                        } else {
                            root = 3;
                        }
                        int other1 = root % 3 + 1, other2 = other1 % 3 + 1;
                        if (m % 4 == 0) {
                            int node = root;
                            cout << root << " ";
                            for (int i = 2; i <= m / 2 + 1; i++) {
                                node = root + other1 - node;
                                cout << node << " ";
                            }
                            for (int i = m / 2 + 2; i <= m + 1; i++) {
                                node = root + other2 - node;
                                cout << node << " ";
                            }
                            cout << "\n";
                        } else {
                            int node = other1;
                            cout << node << " ";
                            for (int i = 2; i <= m / 2 + 1; i++) {
                                node = root + other1 - node;
                                cout << node << " ";
                            }
                            for (int i = m / 2 + 2; i <= m + 1; i++) {
                                node = root + other2 - node;
                                cout << node << " ";
                            }
                            cout << "\n";
                        }
                    }
                }
            }
        }
    }
    //timeDuration();
    return 0;
}