#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[1010], b[1010], flag;
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d",&a[i], &b[i]);
        if(a[i] != b[i]) flag = 1;
    }

    if(flag) {
        printf("rated\n");
        return 0;
    }

    for(int i=1; i<n; i++) {
        if(a[i] > a[i-1]) flag = 1;
    }

    if(flag) {
        printf("unrated\n");
        return 0;
    }

    printf("maybe\n");
    return 0;
}