#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], sz, c, nc;
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;
    sz = str.size();

    for(int i = 0; i < sz; i++) {
        c += (str[i] == 'a');
        nc += (str[i] != 'a');
    }

    if(c > nc) printf("%d\n", c + nc);
    else printf("%d\n", c + c - 1);

    return 0;
}