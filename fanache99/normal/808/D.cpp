#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

long long v[1 + MAXN + 1];
map<long long, int> seen;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &v[i]);
        sum += v[i];
    }
    if (sum % 2) {
        printf("NO\n");
        return 0;
    }
    long long preffix = 0, suffix = 0;
    for (int i = 1; i <= n + 1; i++)
        seen[v[i]]++;
    for (int i = 0; i <= n; i++) {
        preffix += v[i];
        if (preffix > sum / 2)
            break;
        seen[v[i]]--;
        long long need = sum / 2 - preffix;
        if (seen[need] > 0) {
            printf("YES\n");
            return 0;
        }
    }
    seen.clear();
    for (int i = 0; i <= n; i++)
        seen[v[i]]++;
    for (int i = n + 1; i >= 1; i--) {
        suffix += v[i];
        if (suffix > sum / 2)
            break;
        seen[v[i]]--;
        long long need = sum / 2 - suffix;
        if (seen[need] > 0) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}