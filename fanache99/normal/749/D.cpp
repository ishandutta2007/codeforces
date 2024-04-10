#include <cstdio>
//#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 1 << 17;
const int MAXN = 200000;

int pos = 0;
char buffer[SIZE];

char Advance() {
    if (pos == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pos = 0;
    }
    return buffer[pos++];
}

int Read() {
    int number = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        number = number * 10 + ch - '0';
        ch = Advance();
    }
    return number;
}

int money[1 + MAXN], last[1 + MAXN];
int order[1 + MAXN], v[1 + MAXN];
vector<int> moment[1 + MAXN];
bool out[1 + MAXN];

bool Compare(const int &a, const int &b) {
    return last[a] < last[b];
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        moment[a].push_back(i);
        money[i] = b;
        last[a] = i;
        order[i] = i;
    }
    sort(order + 1, order + n + 1, Compare);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &v[j]);
            out[v[j]] = true;
        }
        int winner = n;
        while (winner && out[order[winner]])
            winner--;
        if (!winner || !last[order[winner]])
            printf("0 0\n");
        else {
            out[order[winner]] = true;
            int before = winner - 1;
            while (before && out[order[before]])
                before--;
            int limit = last[order[before]];
            out[order[winner]] = false;
            int left = 0, right = moment[order[winner]].size() - 1, answer = 0;
            while (left <= right) {
                int middle = (left + right) / 2;
                if (moment[order[winner]][middle] >= limit) {
                    answer = money[moment[order[winner]][middle]];
                    right = middle - 1;
                }
                else
                    left = middle + 1;
            }
            printf("%d %d\n", order[winner], answer);
        }
        for (int j = 1; j <= k; j++)
            out[v[j]] = false;
    }
    return 0;
}