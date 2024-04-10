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
    int answer = 0, sign = 1;
    char ch = Advance();
    while (!isdigit(ch) && ch != '-')
        ch = Advance();
    if (ch == '-') {
        sign = -1;
        ch = Advance();
    }
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer * sign;
}

char ReadCh() {
    char ch = Advance();
    while (!isalpha(ch))
        ch = Advance();
    return ch;
}

const int MAXN = 5000;

int v[1 + MAXN];
int dad[1 + MAXN][1 + MAXN];
vector<int> which;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, need, sum = 0;
    scanf("%d%d%d", &n, &k, &need);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
        for (int j = 0; j < k; j++)
            if (dad[i - 1][j] || j == 0) {
                dad[i][j] = dad[i - 1][j];
                dad[i][(j + v[i]) % k] = i;
            }
    }
    if (sum < need) {
        printf("NO\n");
        return 0;
    }
    if (need % k == 0) {
        printf("YES\n");
        for (int i = 2; i <= n; i++)
            if (v[i])
                printf("%d %d %d\n", v[i] / k + (v[i] % k != 0) , i, 1);
        if (need / k != 0)
            printf("%d %d %d\n", need / k, 1, 2);
        return 0;
    }
    if (dad[n][need % k] == 0) {
        printf("NO\n");
        return 0;
    }
    int i = need % k, j = n;
    while (i) {
        which.push_back(dad[j][i]);
        int temp = dad[j][i] - 1;
        i = (i - v[dad[j][i]] % k + k) % k;
        j = temp;
    }
    printf("YES\n");
    for (int i = 0; i < which.size() - 1; i++) {
        if (v[which[i]])
            printf("%d %d %d\n", v[which[i]] / k + (v[which[i]] % k != 0), which[i], which.back());
        v[which.back()] += v[which[i]];
        v[which[i]] = 0;
    }
    int other = 1;
    if (which.back() == 1)
        other = 2;
    for (int i = 1; i <= n; i++)
        if (i != which.back() && i != other && v[i])
            printf("%d %d %d\n", v[i] / k + (v[i] % k != 0), i, other);
    if (v[which.back()] == need)
        return 0;
    if (v[which.back()] > need)
        printf("%d %d %d\n", (v[which.back()] - need) / k, which.back(), other);
    else
        printf("%d %d %d\n", (need - v[which.back()]) / k, other, which.back());
    return 0;
}