#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100000];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        printf("%d\n", strlen(s));
    }
    return 0;
}