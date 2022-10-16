#include <fstream>
//#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXVAL = 60;
const int MAXS = 120000;
const int MOD = 666019;
const int SIZE = 1 << 17;

struct State {
    int sum;
    long long mask;

    bool operator < (const State &other) const {
        return sum < other.sum;
    }
};

State v[1 + MAXS];

int number = 0;
int seen[1 + MAXVAL];
int dp[1 + MAXVAL][1 + MAXS];
vector<pair<long long, int> > table[MOD];

void Add(long long mask, int x) {
    int which = mask % MOD;
    table[which].push_back(make_pair(mask, x));
}

int Get(long long mask) {
    int which = mask % MOD;
    for (auto &it : table[which])
        if (it.first == mask)
            return it.second;
}

int sd;

void Backtracking(long long currentMask, int currentSum, int previous) {
    number++;
    v[number] = {currentSum, currentMask};
    for (int i = previous + 1; currentSum + i <= MAXVAL; i++)
        Backtracking(currentMask ^ (1LL << i), currentSum + i, i);
}

char buffer[SIZE];
int pointer = 0;

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    Backtracking(0, 0, 0);
    sort(v + 1, v + number + 1);
    int x = 0;
    for (int i = 1; i <= number; i++) {
        Add(v[i].mask, i);
    }
    for (int i = 1; i <= MAXVAL; i++)
        for (int j = 1; j <= number && MAXVAL - v[j].sum >= i; j++) {
            x++;
            for (int bit = 1; bit <= i; bit++)
                if (!(v[j].mask & (1LL << bit)))
                    seen[dp[i - bit][Get(v[j].mask ^ (1LL << bit))]] = x;
            while (seen[dp[i][j]] == x)
                dp[i][j]++;
        }
    int n = Read(), sum = 0;
    for (int i = 1; i <= n; i++) {
        x = Read();
        sum ^= dp[x][1];
    }
    if (sum)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}