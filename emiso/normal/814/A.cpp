#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], b[MN], k;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    for(int i=0; i<k; i++) {
        scanf("%d",&b[i]);
    } sort(b, b + k);

    int j = k-1;
    int flag = 0;

    for(int i=0; i<n; i++) {
        if(a[i] == 0)
            a[i] = b[j--];

        if(i && a[i] <= a[i-1]) flag = 1;
    }

    printf("%s\n", flag ? "Yes" : "No");
    return 0;
}