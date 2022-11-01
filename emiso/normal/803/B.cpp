#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, last = -99999999, a[MN], dL[MN], dR[MN];
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i] == 0) last = i;
        dL[i] = i - last;
    }

    last = 99999999;
    for(int i=n-1; i>=0; i--) {
        if(a[i] == 0) last = i;
        dR[i] = last - i;
    }

    for(int i=0; i<n; i++) {
        printf("%d ", min(dR[i], dL[i]));
    }
    return 0;
}