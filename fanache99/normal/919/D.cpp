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

const int MAXN = 300000;

vector<int> g[1 + MAXN];
int inDegree[1 + MAXN], order[1 + MAXN];
int dp[1 + MAXN];
char letter[1 + MAXN];

int Try(int n, char ch) {
    int answer = 0;
    for (int i = n; i >= 1; i--) {
        int node = order[i];
        dp[node] = 0;
        for (auto &son : g[node])
            dp[node] = max(dp[node], dp[son]);
        if (letter[node] == ch)
            dp[node]++;
        answer = max(answer, dp[node]);
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read();
    for (int i = 1; i <= n; i++)
        letter[i] = ReadCh();
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read();
        g[a].push_back(b);
        inDegree[b]++;
    }
    int left = 1, right = 0;
    for (int i = 1; i <= n; i++)
        if (!inDegree[i]) {
            right++;
            order[right] = i;
        }
    while (left <= right) {
        int node = order[left];
        left++;
        for (auto &it : g[node]) {
            inDegree[it]--;
            if (!inDegree[it]) {
                right++;
                order[right] = it;
            }
        }
    }
    if (right != n) {
        printf("-1\n");
        return 0;
    }
    int answer = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
        answer = max(answer, Try(n, ch));
    printf("%d\n", answer);
    return 0;
}