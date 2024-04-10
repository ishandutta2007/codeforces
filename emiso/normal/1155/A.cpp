#include <bits/stdc++.h>

using namespace std;

int n;
char s[400040];
string str;

int main() {
    scanf("%d %s", &n, s); str = s;
    for(int i = 0; i + 1 < n; i++) {
        if(str[i] > str[i+1]) {
            puts("YES");
            printf("%d %d\n", i + 1, i + 2);
            return 0;
        }
    }
    puts("NO");
    return 0;
}