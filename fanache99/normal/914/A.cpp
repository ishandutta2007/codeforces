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

const int INF = 1000000;

bool NotSquare(int x) {
    if (x < 0)
        return true;
    int left = 0, right = 1000, answer = 0;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (middle * middle <= x) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    if (answer * answer == x)
        return false;
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, answer = -INF;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (NotSquare(x))
            answer = max(answer, x);
    }
    printf("%d\n", answer);
    return 0;
}