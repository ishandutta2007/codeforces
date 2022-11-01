#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
long long a[100100];
//char s[MN]; string str;

int main() {
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%lld",&a[i]);
    }

    ll g = a[0];
    for(int i=1;i<n;i++) {
        g = __gcd(g, a[i]);
    }

    if(g > 1) {
        printf("YES\n0\n");
        return 0;
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(a[i] % 2 == 0) continue;
        else if(i < n - 1 && a[i] == a[i+1]) {
            a[i] = 0;
            a[i+1] *= 2;
            ans++;
        }
        else if(i < n - 1 && a[i+1] % 2 == 1){
            ans += 1;
            i++;
        }

        else {
            ans += 2;
            i++;
        }
    }

    printf("YES\n%d\n", ans);
    return 0;
}

/*
4
2 5 5 10

5
1 2 1 2 1

5
1 2 2 1 1
*/