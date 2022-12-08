#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;

int N;
char c[MAXN];

int main() {
    scanf("%d", &N);
    scanf(" %s", c);
    sort(c, c + N);
    printf("%s\n", c);
}