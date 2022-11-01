#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, ans, co;
char a;

int main() {
    scanf("%d ", &n);

    for(int i=0; i<n; i++) {
        scanf("%c",&a);
        if(a == '0') {
            ans = ans * 10 + co;
            co = 0;
        }

        else {
            co++;
        }
    }

    ans = ans * 10 + co;
    co = 0;

    printf("%d\n", ans);
    return 0;
}