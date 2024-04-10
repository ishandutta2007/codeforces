#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], x, b;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &x);

    for(int i=0; i<n; i++) {
        scanf("%d",&b);
        a[b]++;
    } ;

    int ans = 0;
    for(int i=0; i<x; i++) {
        if(a[i] == 0) ans++;
    }
    if(a[x] == 1) ans++;

    printf("%d\n", ans);
    return 0;
}