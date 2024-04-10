//#include <iostream>
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

const int MAXN = 200000;

int v[1 + MAXN], Stack[1 + MAXN + 1];
bool seen[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, top = 0;
    scanf("%d%d", &n, &k);
    int need = 1;
    Stack[0] = n + 1;
    for (int i = 1; i <= k; i++) {
        scanf("%d", &v[i]);
        seen[v[i]] = true;
        if (v[i] == need) {
            need++;
            while (top && Stack[top] == need) {
                top--;
                need++;
            }
            continue;
        }
        if (v[i] > Stack[top]) {
            printf("-1\n");
            return 0;
        }
        top++;
        Stack[top] = v[i];
    }
    for (int i = top; i >= 0; i--)
        for (int j = Stack[i] - 1; j > Stack[i + 1]; j--)
            if (!seen[j]) {
                k++;
                v[k] = j;
            }
    for (int i = 1; i <= n; i++)
        printf("%d ", v[i]);
    return 0;
}