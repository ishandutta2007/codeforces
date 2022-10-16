#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
//#include "cup.h"

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

const int MAXN = 300000;

char s[7];
int Stack[1 + MAXN];
bool ok[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, answer = 0, need = 0, top = 0;
    scanf("%d\n", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%s", s + 1);
        if (s[1] == 'a') {
            int x;
            scanf("%d\n", &x);
            top++;
            Stack[top] = x;
        }
        else {
            need++;
            if (top)
                if (Stack[top] == need)
                    top--;
                else {
                    top = 0;
                    answer++;
                }
        }
    }
    printf("%d\n", answer);
    return 0;
}