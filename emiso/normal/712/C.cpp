#include <bits/stdc++.h>

using namespace std;

int x,y,l[3],i;

int main() {
    scanf("%d %d",&x,&y);

    l[0] = l[1] = l[2] = y;

    while(l[0] != x || l[1] != x || l[2] != x) {
        l[0] = min(x, l[1] + l[2] - 1);
        i++;
        sort(l, l+3);
    }

    printf("%d\n",i);

    return 0;
}