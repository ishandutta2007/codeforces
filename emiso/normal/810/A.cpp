#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, a;
double media, total;
//char s[MN]; string str;

int ro(double x) {
    int dec = x;
    if(x - dec + 1e-6 >= 0.5) x = dec + 1;
    else x = dec;

    return x;
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d",&a);
        total += a;
    }

    media = total / n;

    if(ro(media) == k) printf("0\n");
    else {
        int ans = 0;
        while(1) {
            if(ro(media) == k) break;

            ans++;
            total += k;
            media = total / (n + ans);

        }

        printf("%d\n", ans);
    }
    return 0;
}