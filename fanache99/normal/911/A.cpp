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
const int MAXVAL = 1000000000;

int v[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, small = MAXVAL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        small = min(small, v[i]);
    }
    int answer = n + 1;
    for (int i = 1, last = 0; i <= n; i++)
        if (v[i] == small)
            if (!last)
                last = i;
            else {
                answer = min(answer, i - last);
                last = i;
            }
    printf("%d\n", answer);
    return 0;
}