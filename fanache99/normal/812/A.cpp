#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

int l[4], s[4], r[4], p[4];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    for (int i = 0; i < 4; i++)
        scanf("%d%d%d%d", &l[i], &s[i], &r[i], &p[i]);
    for (int i = 0; i < 4; i++)
        if (p[i] && (l[i] || s[i] || r[i] || l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4])) {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}