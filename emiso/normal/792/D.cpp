#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int q;
ll n, u;
char s[MN]; string str;

ll lft(ll pos) {
    if(pos & 1) return pos;
    ll last = (pos & -pos);
    return pos - last/2;
}

ll rit(ll pos) {
    if(pos & 1) return pos;
    ll last = (pos & -pos);
    return pos + last/2;
}

ll up(ll pos) {
    ll last = (pos & -pos);
    if(last * 2 - 1 == n) return pos;

    if(last * 2 & pos) return pos - last;
    return pos + last;
}

int main() {
    scanf("%lld %d", &n, &q);

    for(int i=0; i<q; i++) {
        scanf("%lld %s", &u, s);
        str = s;

        for(int k=0;k<str.size();k++) {
            if(str[k] == 'U') u = up(u);
            if(str[k] == 'L') u = lft(u);
            if(str[k] == 'R') u = rit(u);
        }
        printf("%lld\n", u);
    }
    return 0;
}