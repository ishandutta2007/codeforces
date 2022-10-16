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

const int MAXN = 1000;
const int SIGMA = 26;

int have[SIGMA];
char s[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n%s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        memset(have, 0, sizeof(have));
        int biggest = 0;
        for (int j = i; j <= n; j++) {
            have[s[j] - 'a']++;
            biggest = max(biggest, have[s[j] - 'a']);
            if (biggest <= (j - i + 1) / 2) {
                printf("YES\n");
                for (int k = i; k <= j; k++)
                    printf("%c", s[k]);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}