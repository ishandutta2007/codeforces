#include <bits/stdc++.h>
using namespace std;
char s[100010];
int n, t;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%*d%s", s + 1);
        n = strlen(s + 1);
        int _min = n + 1, _max = 0;
        for(int i = 1; i <= n; i++) if(s[i] == '1') _min = min(_min, i), _max = max(_max, i);
        if(_max == 0) printf("%d\n", n);
        else printf("%d\n", max(_max, n - _min + 1) * 2);
    }
}