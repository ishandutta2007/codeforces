#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, c, b, ans, x;
//char s[MN]; string str;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &n);

    for(int i=0; i<n; i++) {
        scanf("%d",&x);
        if(b < x && x < c) ans++;
    }

    printf("%d\n", ans);
    return 0;
}