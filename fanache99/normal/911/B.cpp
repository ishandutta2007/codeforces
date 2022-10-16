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

bool Check(int x, int n, int a, int b) {
    if (a / x + b / x >= n && a / x >= 1 && b / x >= 1)
        return true;
    return false;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int left = 1, right = max(a, b), answer = 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (Check(middle, n, a, b)) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    printf("%d\n", answer);
    return 0;
}