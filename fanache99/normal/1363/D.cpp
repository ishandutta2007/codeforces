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
const int MAXK = 1000;

vector<int> g[1 + MAXN];
vector<int> s[1 + MAXK];
int big[1 + MAXK];

int query(vector<int> &v) {
    cout << "? " << v.size();
    for (auto it : v) {
        cout << " " << it;
    }
    cout << "\n";
    cout.flush();
    int answer;
    cin >> answer;
    return answer;
}

int ask(int a, int b) {
    vector<int> v;
    for (int i = a; i <= b; i++) {
        v.emplace_back(i);
    }
    return query(v);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            int l;
            cin >> l;
            for (int j = 1; j <= l; j++) {
                int x;
                cin >> x;
                s[i].emplace_back(x);
            }
        }
        int biggest = ask(1, n), left = 1, right = n;
        while (left < right) {
            int middle = (left + right) / 2, value = ask(left, middle);
            if (value == biggest) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        for (int i = 1; i <= k; i++) {
            bool found = false;
            for (auto it : s[i]) {
                if (it == left) {
                    found = true;
                }
            }
            if (!found) {
                big[i] = biggest;
            } else {
                vector<int> v;
                for (int j = 1; j <= n; j++) {
                    if (count(s[i].begin(), s[i].end(), j) == 0) {
                        v.emplace_back(j);
                    }
                }
                big[i] = query(v);
            }
        }
        cout << "!";
        for (int i = 1; i <= k; i++) {
            cout << " " << big[i];
            s[i].clear();
        }
        cout << "\n";
        cout.flush();
        string s;
        cin >> s;
    }
    //timeDuration();
    return 0;
}