#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, l[4], m[4], r[4], p[4], flag = 1;
//char s[MN]; string str;

int main() {
    for(int i=0; i<4; i++) {
        scanf("%d %d %d %d", &l[i], &m[i], &r[i], &p[i]);
    }

    for(int i=0; i<4; i++) {
        if(p[i] && (l[i] || m[i] || r[i])) flag = 0;
        if(r[i] && p[(i + 1)%4]) flag = 0;
        if(m[i] && p[(i + 2)%4]) flag = 0;
        if(l[i] && p[(i + 3)%4]) flag = 0;
    }

    printf("%s\n", flag ? "NO" : "YES");
    return 0;
}