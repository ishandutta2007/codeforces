#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, b, c, ans, pos = 0;

int main() {
    scanf("%d %d %d %d", &n, &a, &b, &c);

    for(int i=1; i<n; i++) {
        if(pos == 0) {
            if(a < b) {
                pos = 1;
                ans += a;
            }

            else {
                pos = 2;
                ans += b;
            }
        }

        else if(pos == 1) {
            if(a < c) {
                pos = 0;
                ans += a;
            }

            else {
                pos = 2;
                ans += c;
            }
        }

        else {
            if(b < c) {
                pos = 0;
                ans += b;
            }

            else {
                pos = 1;
                ans += c;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}