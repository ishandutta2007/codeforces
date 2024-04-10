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

vector<pair<int, int> > answer;


int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    int p2 = 1;
    while (p2 * 2 <= n) {
        p2 *= 2;
    }
    vector<vector<int> > sets;
    for (int i = 1; i <= p2; i++) {
        sets.push_back({i});
    }
    while (sets.size() > 1) {
        vector<vector<int> > newSets;
        for (int i = 0; i < sets.size(); i += 2) {
            newSets.push_back({});
            for (int j = 0; j < sets[i].size(); j++) {
                answer.emplace_back(sets[i][j], sets[i + 1][j]);
                newSets.back().push_back(sets[i][j]);
                newSets.back().push_back(sets[i + 1][j]);
            }
        }
        sets = newSets;
    }
    vector<int> temp = sets[0];
    sets.clear();
    for (int i = p2 + 1; i <= n; i++) {
        sets.push_back({i});
    }
    while (sets.size() > 1) {
        vector<vector<int> > newSets;
        for (int i = 0; i < sets.size(); i += 2) {
            newSets.push_back({});
            if (i + 1 < sets.size()) {
                for (int j = 0; j < sets[i].size(); j++) {
                    answer.emplace_back(sets[i][j], sets[i + 1][j]);
                    newSets.back().push_back(sets[i][j]);
                    newSets.back().push_back(sets[i + 1][j]);
                }
            } else {
                for (int j = 0; j < sets[i].size(); j++) {
                    answer.emplace_back(sets[i][j], temp.back());
                    newSets.back().push_back(sets[i][j]);
                    newSets.back().push_back(temp.back());
                    temp.pop_back();
                }
            }
        }
        sets = newSets;
    }
    cout << answer.size() << "\n";
    for (auto it : answer) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}