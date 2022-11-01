#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, f[10];
char a[110]; string str;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(f, 0, sizeof f);
        int sum = 0;

        scanf("%s", a);
        str = a;

        for(int i = 0; i < str.size(); i++) {
            f[a[i] - '0']++;
            sum += (a[i] - '0');
        }

        if(sum % 3 == 0 && f[0] && (f[0] > 1 || f[2] || f[4] || f[6] || f[8]))
            puts("red");
        else puts("cyan");
    }
    return 0;
}