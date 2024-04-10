#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000;
char a[N], b[N], c[N];
bool check(char c) {
    return c >= 'a' && c <= 'z';
}
void getline(char *s) {
    while (!check(s[0] = getchar()));
    s++;
    while (check(s[0] = getchar())) s ++;

        s[0] = 0;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        getline(a), getline(b), getline(c);
        int n = strlen(a);
        bool sig = 1;
        for (int i = 0; i < n; i ++)
            sig &= (c[i] == b[i] || c[i] == a[i]);
        sig?puts("YES"):puts("NO");
    }
    return 0;
}