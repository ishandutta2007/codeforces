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
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        length[i] = length[i - 1];
        last[i] = last[i - 1];
        if (v[i] > last[i]) {
            last[i] = v[i];
            length[i]++;
        }
    }
    int top = 0, answer = -1, which = 0;
    for (int i = n; i >= 1; i--) {
        int now = length[i - 1] + BinarySearch(top, last[i - 1]);
        if (now > answer || (now == answer && v[i] < v[which])) {
            answer = now;
            which = i;
        }
        while (top && v[i] >= v[Stack[top]])
            top--;
        top++;
        Stack[top] = i;
    }
    printf("%d\n", v[which]);
    return 0;
}