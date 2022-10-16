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

const int MAXN = 1000;

vector<int> answer;

int v[1 + MAXN];
int x[1 + MAXN];

bool Good(int n, int k) {
    for (int i = 1; i <= n; i++) {
        int id = (i - 1) % k;
        if ((i - 1) < k)
            x[id] = v[i] - v[i - 1];
        else
            if (x[id] != v[i] - v[i - 1])
                return false;
    }
    return true;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int k = 1; k <= n; k++)
        if (Good(n, k))
            answer.push_back(k);
    printf("%d\n", answer.size());
    for (auto &it : answer)
        printf("%d ", it);
    return 0;
}