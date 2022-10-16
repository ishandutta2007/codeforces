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
#include <cassert>

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

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, p, l, r;
    scanf("%d%d%d%d", &n, &p, &l, &r);
    if (l == 1 && r == n)
        printf("0\n");
    else
        if (l == 1)
            printf("%d\n", abs(p - r) + 1);
        else
            if (r == n)
                printf("%d\n", abs(p - l) + 1);
            else
                if (p < l)
                    printf("%d\n", abs(p - r) + 2);
                else
                    if (p > r)
                        printf("%d\n", abs(p - l) + 2);
                    else
                        printf("%d\n", min(r - p, p - l) + r - l + 2);
    return 0;
}