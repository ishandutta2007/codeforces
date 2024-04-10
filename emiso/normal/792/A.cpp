#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], minimal, quant = 1;
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    } sort(a, a + n);

    minimal = a[1] - a[0];
    for(int i=2; i<n;i++) {
        if(a[i] - a[i-1] == minimal)
            quant++;
        if(a[i] - a[i-1] < minimal) {
            quant = 1;
            minimal = a[i] - a[i-1];
        }
    }

    printf("%d %d\n", minimal, quant);
    return 0;
}