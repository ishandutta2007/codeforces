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

const int MAXN = 100000;

char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s", s + 1);
    int n = strlen(s + 1), a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a')
            a++;
        if (s[i] == 'b')
            b++;
        if (s[i] == 'c')
            c++;
        if (s[i] < s[i - 1]) {
            printf("NO\n");
            return 0;
        }
    }
    if (a != 0 && b != 0 && (a == c || b == c))
        printf("YES");
    else
        printf("NO");
    return 0;
}