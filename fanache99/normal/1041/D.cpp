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

const int MAXN = 200000;

int a[1 + MAXN], b[1 + MAXN];
deque<int> Deque;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i], &b[i]);
    int answer = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        Deque.push_front(i);
        sum += b[i] - a[i];
        while (a[Deque.back()] - a[i] - (sum - b[Deque.back()] + a[Deque.back()])>= h) {
            sum -= b[Deque.back()] - a[Deque.back()];
            Deque.pop_back();
        }
        answer = max(answer, sum + h);
    }
    printf("%d\n", answer);
    return 0;
}