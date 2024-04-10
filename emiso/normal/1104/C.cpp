#include <bits/stdc++.h>

using namespace std;

char s[10100]; string str;
pair<int, int> pos[2][4] = {{{1, 1}, {1, 2}, {1, 3}, {1, 4}}, {{3, 1}, {3, 3}, {4, 1}, {4, 3}}};
int now[2];

int main() {
    scanf("%s", s); str = s;

    for(int c : str) {
        int x = c-'0';
        printf("%d %d\n", pos[x][now[x]].first, pos[x][now[x]].second);
        now[x] = (now[x] + 1) % 4;
    }

    return 0;
}