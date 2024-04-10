#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, c, x, y;
ll ans, a[MN];
char s[MN], last; string str;

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    str = s;
    last = '$';

    for(int i=0; i<n; i++) {
        if(x == y && str[i] == last) c++;
        if(str[i] == 'R') x++;
        if(str[i] == 'U') y++;
        last = str[i];
    }

    printf("%d\n", c);
    return 0;
}