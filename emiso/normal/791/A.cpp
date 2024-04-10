#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, m, ans = 0;
//char s[MN]; string str;

int main() {
    scanf("%d %d",&n, &m);

    while(n <= m) {
        ans++;
        n *= 3;
        m *= 2;
    }

    printf("%d\n", ans);
    return 0;
}