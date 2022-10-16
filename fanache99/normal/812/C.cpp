#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>

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

const int MAXN = 100000;

int v[1 + MAXN], temp[1 + MAXN];

int Check(int n, int limit, int taken) {
    for (int i = 1; i <= n; i++)
        temp[i] = min(1LL * limit + 1, v[i] + 1LL * i * taken);
    sort(temp + 1, temp + n + 1);
    int sum = 0;
    for (int i = 1; i <= taken; i++) {
        sum += temp[i];
        if (sum > limit)
            return -1;
    }
    return sum;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), limit = Read();
    for (int i = 1; i <= n; i++)
        v[i] = Read();
    int left = 1, right = n, answer = 0, best = 0;
    while (left <= right) {
        int middle = (left + right) / 2, current = Check(n, limit, middle);
        if (current != -1) {
            answer = middle;
            left = middle + 1;
            best = current;
        }
        else
            right = middle - 1;
    }
    printf("%d %d\n", answer, best);
    return 0;
}