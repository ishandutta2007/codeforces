#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 1 << 17;
const int MAXN = 100000;

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

int a[1 + MAXN], b[1 + MAXN], order[1 + MAXN];
vector<int> answer;

inline bool Compare(const int &x, const int &y) {
    return a[x] > a[y];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        order[i] = i;
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    sort(order + 1, order + n + 1, Compare);
    answer.push_back(order[1]);
    for (int i = 2; i <= n; i += 2)
        if (i + 1 <= n && b[order[i + 1]] > b[order[i]])
            answer.push_back(order[i + 1]);
        else
            answer.push_back(order[i]);
    printf("%d\n", answer.size());
    for (auto &it : answer)
        printf("%d ", it);
    return  0;
}