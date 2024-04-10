
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

const int MAXN = 300000;
const int INF = 2000000000;

int x[1 + MAXN];
char c[1 + MAXN];
vector<int> r, b;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %c", &x[i], &c[i]);
    long long answer = 0;
    int a = 1, lr = 0, lb = 0;
    while (a <= n) {
        if (c[a] == 'G') {
            if (lr)
                answer += x[a] - lr;
            if (lb)
                answer += x[a] - lb;
            break;
        }
        if (c[a] == 'R') {
            if (lr)
                answer += x[a] - lr;
            lr = x[a];
        }
        if (c[a] == 'B') {
            if (lb)
                answer += x[a] - lb;
            lb = x[a];
        }
        a++;
    }
    if (a == n + 1) {
        printf("%I64d\n", answer);
        return 0;
    }
    lr = lb = 0;
    int b = n;
    while (b >= 1) {
        if (c[b] == 'G') {
            if (lr)
                answer += lr - x[b];
            if (lb)
                answer += lb - x[b];
            break;
        }
        if (c[b] == 'R') {
            if (lr)
                answer += lr - x[b];
            lr = x[b];
        }
        if (c[b] == 'B') {
            if (lb)
                answer += lb - x[b];
            lb = x[b];
        }
        b--;
    }
    if (a == b) {
        printf("%I64d\n", answer);
        return 0;
    }
    int i = a;
    while (i < b) {
        int lr = x[i], lb = x[i];
        int br = 0, bb = 0;
        int j = i + 1;
        while (c[j] != 'G') {
            if (c[j] == 'R') {
                br = max(br, x[j] - lr);
                lr = x[j];
            }
            if (c[j] == 'B') {
                bb = max(bb, x[j] - lb);
                lb = x[j];
            }
            j++;
        }
        if (lr != x[i])
            br = max(br, x[j] - lr);
        if (lb != x[i])
            bb = max(bb, x[j] - lb);
        if (br == 0 || bb == 0) {
            answer += x[j] - x[i];
            if (bb != 0)
                answer += x[j] - x[i] - bb;
            if (br != 0)
                answer += x[j] - x[i] - br;
        }
        else
            if (x[j] - x[i] >= br + bb)
                answer += 2LL * (x[j] - x[i]);
            else
                answer += 3LL * (x[j] - x[i]) - br - bb;
        i = j;
    }
    printf("%I64d\n", answer);
    return 0;
}