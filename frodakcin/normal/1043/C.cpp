#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXS = 1e3 + 100;
int S;
char s[MAXS];

int main() {
    scanf(" %s", s);
    for(S = 0;s[S] != '\0';S++) assert(S < MAXS);
    
    for(int i = 0;i < S - 1;i++) {
        printf("%d ", s[i] != s[i + 1]);
    }
    printf("%d\n", s[S - 1] == 'a');
}