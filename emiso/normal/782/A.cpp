#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, x, s[MN], ans, tbl;

int main() {
    scanf("%d",&n);

    for(int i=0; i<2*n; i++) {
        scanf("%d",&x);
        if(s[x] == 0) {
            tbl++;
            s[x] = 1;
        }

        else {
            tbl--;
            s[x] = 2;
        }

        ans = max(ans, tbl);
    }

    printf("%d\n",ans);
    return 0;
}