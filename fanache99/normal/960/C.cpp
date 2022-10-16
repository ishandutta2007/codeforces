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

const int MAXLOG = 30;

vector<long long> v;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int x, d;
    scanf("%d%d", &x, &d);
    long long a = 1;
    for (int i = 0; i <= MAXLOG; i++)
        if (x & (1 << i)) {
            for (int j = 1; j <= i; j++)
                v.push_back(a);
            a += d;
            v.push_back(a);
            a += d;
        }
    printf("%d\n", v.size());
    for (auto &it : v)
        printf("%I64d ", it);
    return 0;
}