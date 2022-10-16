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

const int MAXN = 100000;

vector<int> v[MAXN];
int answer[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        v[x].push_back(i);
    }
    int number = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].size() % (n - i) != 0) {
            printf("Impossible\n");
            return 0;
        }
        for (int j = 0; j < v[i].size(); j += n - i) {
            number++;
            for (int k = j; k < j + n - i; k++)
                answer[v[i][k]] = number;
        }
    }
    printf("Possible\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", answer[i]);
    return 0;
}