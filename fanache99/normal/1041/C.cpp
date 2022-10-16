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

pair<int, int> v[1 + MAXN];
priority_queue<pair<int, int> > Heap;
int day[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), d = Read();
    for (int i = 1; i <= n; i++)
        v[i] = make_pair(Read(), i);
    sort(v + 1, v + n + 1);
    int answer = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        if (Heap.empty() || v[i].first - (-Heap.top().first) <= d) {
            answer++;
            day[v[i].second] = answer;
            Heap.push(make_pair(-v[i].first, answer));
        }
        else {
            day[v[i].second] = Heap.top().second;
            Heap.pop();
            Heap.push(make_pair(-v[i].first, day[v[i].second]));
        }
    }
    printf("%d\n", answer);
    for (int i = 1; i <= n; i++)
        printf("%d ", day[i]);
    return 0;
}