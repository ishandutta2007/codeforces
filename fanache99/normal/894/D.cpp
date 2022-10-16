#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>

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

const int MAXN = 1000000;

vector<int> sons[1 + MAXN];
vector<long long> sum[1 + MAXN];
int cost[1 + MAXN];

pair<int, long long> BinarySearch(int which, int x) {
    if (sons[which][0] > x)
        return make_pair(0, 0);
    if (sons[which].back() <= x)
        return make_pair(sons[which].size(), sum[which].back());
    int left = 0, right = sons[which].size() - 1, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (sons[which][middle] <= x) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    return make_pair(answer + 1, sum[which][answer]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    sons[1].push_back(0);
    for (int i = 2; i <= n; i++) {
        cost[i] = Read();
        sons[i].push_back(0);
        for (int j = i, value = 0; j != 1; j /= 2) {
            value += cost[j];
            sons[j / 2].push_back(value);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(sons[i].begin(), sons[i].end());
        sum[i].resize(sons[i].size());
        sum[i][0] = sons[i][0];
        for (int j = 1; j < sons[i].size(); j++)
            sum[i][j] = sum[i][j - 1] + sons[i][j];
    }
    for (int i = 1; i <= m; i++) {
        int node = Read(), limit = Read();
        pair<int, long long> now = BinarySearch(node, limit);
        //printf("%d %I64d\n", now.first, now.second);
        long long answer = 1LL * now.first * limit - now.second;
        //printf("%I64d\n", answer);
        for (int j = node, value = 0; j != 1; j /= 2) {
            value += cost[j];
            pair<int, long long> now = BinarySearch(j / 2, limit - value), before = BinarySearch(j, limit - value - cost[j]);
            //printf("%d %I64d\n", now.first, now.second);
            //printf("%d %I64d\n", before.first, before.second);
            answer += 1LL * now.first * (limit - value) - now.second - (1LL * before.first * (limit - value - cost[j]) - before.second);
            //printf("%I64d\n", answer);
        }
        printf("%I64d\n", answer);
    }
    return 0;
}