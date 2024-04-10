/* Written by Filip Hlasek 2017 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

#define MAXN 111111
char cmd[5];
char text[MAXN];

const int C = 26;
bool done[33];
bool contains[33];

int main(int argc, char* argv[]) {
    int Q;
    scanf("%d", &Q);
    int ans = 0, options = C;
    while (Q--) {
        scanf("%s%s", cmd, text);
        REP(i, C) contains[i] = false;
        int N = strlen(text);
        REP(i, N) contains[text[i] - 'a'] = true;
        if (cmd[0] == '!' && options == 1) {
            ans++;
        }
        if (cmd[0] == '?' && Q && options == 1) {
            ans++;
        }
        REP(i, C) if (!done[i]) {
            if (cmd[0] == '!' && !contains[i]) {
                done[i] = true;
                options--;
            }
            if (cmd[0] != '!' && contains[i]) {
                done[i] = true;
                options--;
            }
        }
        // printf("options: %d\n", options);
    }
    printf("%d\n", ans);
    return 0;
}