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

const int MAXN = 300000;

char s[1 + MAXN];
pair<int, int> v[1 + MAXN], w[1 + MAXN];
map<int, int> delta;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d\n", &n);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        int l = strlen(s + 1);
        v[i].first = MAXN;
        for (int j = 1; j <= l; j++) {
            if (s[j] == '(')
                v[i].second++;
            else
                v[i].second--;
            v[i].first = min(v[i].first, v[i].second);
        }
        w[i] = make_pair(v[i].second, v[i].first);
    }
    sort(v + 1, v + n + 1);
    sort(w + 1, w + n + 1);
    for (int i = 1, j = n; i <= n; i++) {
        while (j >= 1 && v[j].first >= -w[i].first) {
            delta[v[j].second]++;
            j--;
        }
        if (w[i].second < 0)
            continue;
        answer += delta[-w[i].first];
    }
    printf("%I64d\n", answer);
    return 0;
}