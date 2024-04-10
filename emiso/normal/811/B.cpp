#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, p[10010], l, r, x;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        scanf("%d",&p[i]);
    }

    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &l, &r, &x);

        int pos = l, num = p[x];
        for(int i=l; i<=r; i++) {
            if(p[i] < p[x]) pos++;
        }

        if(pos == x) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}