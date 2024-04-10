#include <bits/stdc++.h>

using namespace std;

int n, a[110], rat, flag;

int main() {
    scanf("%d", &n);
    scanf("%d %d", &a[0], &a[1]);

    rat = a[1] - a[0];
    flag = true;

    for(int i = 2; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] - a[i-1] != rat) flag = false;
    }

    if(!flag) rat = 0;
    printf("%d\n", a[n-1] + rat);

    return 0;
}