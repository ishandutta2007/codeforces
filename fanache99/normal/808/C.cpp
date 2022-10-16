#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <queue>

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

const int MAXN = 100;

pair<int, int> v[1 + MAXN];
int answer[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, w;
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        answer[v[i].second] = (v[i].first + 1) / 2;
        sum += (v[i].first + 1) / 2;
    }
    if (sum > w) {
        printf("-1\n");
        return 0;
    }
    w -= sum;
    for (int i = n; i >= 1; i--)
        if (w > v[i].first - answer[v[i].second]) {
            w -= v[i].first - answer[v[i].second];
            answer[v[i].second] = v[i].first;
        }
        else {
            answer[v[i].second] += w;
            w = 0;
            break;
        }
    if (w) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}