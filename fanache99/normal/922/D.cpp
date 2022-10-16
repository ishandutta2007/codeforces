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

const int MAXN = 100000;

char word[1 + MAXN];
pair<int, int> v[1 + MAXN];

int Inside(int n, int id) {
    long long answer = 0;
    for (int i = 1; i <= n; i++)
        if (word[i] == 'h') {
            answer += v[id].first;
            v[id].second++;
        }
        else
            v[id].first++;
    return answer;
}

inline bool Compare(const pair<int, int> &a, const pair<int, int> &b) {
    return 1LL * a.first * b.second > 1LL * b.first * a.second;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    long long answer = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s\n", word + 1);
        int l = strlen(word + 1);
        answer += Inside(l, i);
    }
    sort(v + 1, v + n + 1, Compare);
    for (int i = n; i >= 1; i--) {
        answer += sum * v[i].first;
        sum += v[i].second;
    }
    printf("%I64d\n", answer);
    return 0;
}