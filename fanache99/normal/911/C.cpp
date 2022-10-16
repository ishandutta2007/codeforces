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

void Reorder(int &a, int &b, int &c) {
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    Reorder(a, b, c);
    if (a == 1) {
        printf("YES\n");
        return 0;
    }
    if (a == 2 && b == 2) {
        printf("YES\n");
        return 0;
    }
    if (a == 3 && b == 3 && c == 3) {
        printf("YES\n");
        return 0;
    }
    if (a == 2 && b == 4 && c == 4) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}