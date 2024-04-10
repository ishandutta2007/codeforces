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

int v[1 + MAXN], last[1 + MAXN], length[1 + MAXN], Stack[1 + MAXN];

int BinarySearch(int n, int x) {
    int left = 1, right = n, answer = n + 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (x >= v[Stack[middle]]) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    return answer - 1;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, small = 0, big = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x < 0)
            small++;
        else
            big++;
    }
    if (small <= 1 || big <= 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}