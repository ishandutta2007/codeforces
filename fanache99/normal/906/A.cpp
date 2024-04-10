//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>

using namespace std;

const int SIZE = 1 << 17;
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

const int MAXN = 100000;
const int SIGMA = 26;

char s[1 + MAXN];
bool ok[SIGMA];
int last[SIGMA];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    bool ready = false;
    int answer = -1;
    for (int i = 0; i < SIGMA; i++)
        ok[i] = true;
    for (int i = 1; i <= n; i++) {
        char type;
        scanf("%c %s\n", &type, s + 1);
        if (ready) {
            if (type == '?' || type == '!')
                answer++;
            continue;
        }
        if (type == '.') {
            int l = strlen(s + 1);
            for (int j = 1; j <= l; j++)
                last[s[j] - 'a'] = i;
            for (int j = 0; j < SIGMA; j++)
                if (last[j] == i)
                    ok[j] = false;
        }
        if (type == '!') {
            int l = strlen(s + 1);
            for (int j = 1; j <= l; j++)
                last[s[j] - 'a'] = i;
            for (int j = 0; j < SIGMA; j++)
                if (last[j] != i)
                    ok[j] = false;
        }
        if (type == '?')
            ok[s[1] - 'a'] = false;
        int possible = 0;
        for (int i = 0; i < SIGMA; i++)
            if (ok[i])
                possible++;
        if (possible == 1)
            ready = true;
    }
    if (!ready)
        printf("0\n");
    else
        printf("%d\n", answer);
    return 0;
}