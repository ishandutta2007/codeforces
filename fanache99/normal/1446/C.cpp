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

const int MAXN = 200000;
const int MAXLOG = 29;

struct Node {
    int weight;
    Node *son[2];

    Node() {
        weight = 0;
        son[0] = son[1] = nullptr;
    }
};

void insert(Node *root, int x) {
    Node *node = root;
    node->weight++;
    for (int i = MAXLOG; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (!node->son[bit]) {
            node->son[bit] = new Node();
        }
        node = node->son[bit];
        node->weight++;
    }
}

int answer;

void DFS(Node *node, int out) {
    if (node->weight <= 2) {
        answer = min(answer, out);
        return;
    }
    int toLeft = node->son[0] ? node->son[0]->weight : 0;
    int toRight = node->son[1] ? node->son[1]->weight : 0;
    if (toLeft) {
        DFS(node->son[0], out + max(0, toRight - 1));
    }
    if (toRight) {
        DFS(node->son[1], out + max(0, toLeft - 1));
    }
}

int main() {
    //timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int n;
    cin >> n;
    Node *root = new Node();
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    answer = n;
    DFS(root, 0);
    cout << answer << "\n";
    return 0;
}