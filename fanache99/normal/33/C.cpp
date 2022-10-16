
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

int v[1 + MAXN], preffix[1 + MAXN], sum[1 + MAXN], suffix[1 + MAXN + 1];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, answer = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++)
        preffix[i] = max(preffix[i - 1] + v[i], -sum[i]);
    for (int i = n; i >= 1; i--) {
        suffix[i] = max(suffix[i + 1] + v[i], -(sum[n] - sum[i - 1]));
        answer = max(answer, preffix[i - 1] + suffix[i]);
    }
    printf("%d\n", answer);
    return 0;
}