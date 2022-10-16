#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

const int MAXM = 300000;

vector<int> v[4], w[4];
long long good[1 + MAXM], dp[1 + MAXM];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int w, c;
        scanf("%d%d", &w, &c);
        v[w].push_back(c);
    }
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    sort(v[3].begin(), v[3].end());
    w[1] = v[1];
    w[2] = v[2];
    int weight = 0;
    long long cost = 0;
    while (v[1].size() > 1 || !v[2].empty()) {
        weight += 2;
        if (v[1].size() <= 1 || (v[1].size() > 1 && !v[2].empty() && v[1].back() + v[1][v[1].size() - 2] <= v[2].back())) {
            cost += v[2].back();
            dp[weight] = cost;
            v[2].pop_back();
        }
        else {
            cost += v[1].back();
            v[1].pop_back();
            cost += v[1].back();
            v[1].pop_back();
            dp[weight] = cost;
        }
    }
    if (!w[1].empty()) {
        cost = 0;
        long long add = w[1].back();
        w[1].pop_back();
        weight = 1;
        dp[1] = add;
        while (w[1].size() > 1 || !w[2].empty()) {
            weight += 2;
            if (w[1].size() <= 1 || (w[1].size() > 1 && !w[2].empty() && w[1].back() + w[1][w[1].size() - 2] <= w[2].back())) {
                cost += w[2].back();
                dp[weight] = cost + add;
                w[2].pop_back();
            }
            else {
                cost += w[1].back();
                w[1].pop_back();
                cost += w[1].back();
                w[1].pop_back();
                dp[weight] = cost + add;
            }
        }
    }
    long long answer = 0;
    for (int i = 1; i <= m; i++)
        dp[i] = max(dp[i], dp[i - 1]);
    reverse(v[3].begin(), v[3].end());
    long long sum3 = 0;
    for (int i = 0; i <= v[3].size(); i++) {
        if (3 * i <= m)
            answer = max(answer, sum3 + dp[m - 3 * i]);
        if (i < v[3].size())
            sum3 += v[3][i];
    }
    printf("%I64d\n", answer);
    return 0;
}