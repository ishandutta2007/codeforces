#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

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

const int INF = 1000000000;
const int MAXN = 2000;
const int MAXS = 715;
const int CAP = 4;
const int MAXL = 9;

int dp[2][1 + MAXS], number = 0, people, now, before;
map<vector<int>, int> code;
int inside[1 + MAXS];
map<int, vector<int> > decode;
map<pair<int, pair<int, int> >, int> transition;
map<pair<int, int>, int> add;
vector<int> state;

void Backtracking(int level, int last) {
    if (level == CAP) {
        number++;
        people = 0;
        for (int i = 0; i < CAP; i++)
            if (state[i])
                people++;
        code[state] = number;
        inside[number] = people;
        decode[number] = state;
        return;
    }
    for (int i = last; i <= MAXL; i++) {
        state[level] = i;
        Backtracking(level + 1, i);
    }
}

void Move(int id, int from, int to) {
    state = decode[id];
    for (int i = 0; i < CAP; i++)
        if (state[i] >= from && state[i] <= to)
            state[i] = 0;
    sort(state.begin(), state.end());
    transition[make_pair(id, make_pair(from, to))] = code[state];
}

void Add(int id, int x) {
    if (inside[id] == CAP)
        return;
    state = decode[id];
    state[0] = x;
    sort(state.begin(), state.end());
    add[make_pair(id, x)] = code[state];
}

void Initialize() {
    state.resize(CAP);
    Backtracking(0, 0);
    for (int i = 1; i <= number; i++)
        for (int a = 1; a <= MAXL; a++) {
            Add(i, a);
            for (int b = a; b <= MAXL; b++)
                Move(i, a, b);
        }
    now = 0;
    before = 1;
    state[0] = state[1] = state[2] = state[3] = 0;
    for (int i = 1; i <= MAXS; i++)
        dp[now][i] = INF;
    dp[now][code[state]] = 0;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    Initialize();
    int last = 1, answer = INF;
    for (int step = 1; step <= n; step++) {
        int a, b;
        scanf("%d%d", &a, &b);
        swap(now, before);
        for (int i = 1; i <= number; i++)
            dp[now][i] = INF;
        int smaller = min(a, last), bigger = max(a, last);
        for (int id = 1; id <= number; id++)
            if (dp[before][id] != INF) {
                int other = transition[make_pair(id, make_pair(smaller, bigger))];
                if (inside[other] != CAP) {
                    other = add[make_pair(other, b)];
                    dp[now][other] = min(dp[now][other], dp[before][id] + bigger - smaller);
                }
                for (int from = 1; from < smaller; from++) {
                    int other = transition[make_pair(id, make_pair(from, bigger))];
                    if (inside[other] != CAP) {
                        other = add[make_pair(other, b)];
                        dp[now][other] = min(dp[now][other], dp[before][id] + abs(last - from) + abs(from - a));
                    }
                }
                for (int to = bigger + 1; to <= MAXL; to++) {
                    int other = transition[make_pair(id, make_pair(smaller, to))];
                    if (inside[other] != CAP) {
                        other = add[make_pair(other, b)];
                        dp[now][other] = min(dp[now][other], dp[before][id] + abs(last - to) + abs(to - a));
                    }
                }
            }
        last = a;
    }
    for (int id = 1; id <= number; id++)
        for (int from = 1; from <= MAXL; from++)
            for (int to = from; to <= MAXL; to++)
                if (last >= from && last <= to) {
                    int other = transition[make_pair(id, make_pair(from, to))];
                    if (other == 1)
                        answer = min(answer, dp[now][id] + 2 * (to - from) - max(last - from, to - last));
                }
    printf("%d\n", answer + 2 * n);
    return 0;
}