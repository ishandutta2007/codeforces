#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, k, flag, pos = 1, h, hole[MN], u, v;
//char s[MN]; string str;

int main() {
    scanf("%d %d %d",&n ,&m, &k);

    for(int i=0; i<m; i++) {
        scanf("%d",&h);
        hole[h] = 1;
    }

    if(hole[pos]) flag = 1;
    for(int i=0; i<k; i++) {
        scanf("%d %d",&u, &v);
        if(flag) continue;

        if(pos == u) {
            pos = v;
        }
        else if(pos == v) {
            pos = u;
        }

        if(hole[pos]) flag = 1;
    }

    printf("%d\n", pos);
    return 0;
}