#include <bits/stdc++.h>

using namespace std;

int n, a, neg, pos;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(a < 0) neg++;
        else if(a > 0) pos++;
    }

    if(neg >= (n + 1) / 2) puts("-1");
    else if(pos >= (n + 1) / 2) puts("1");
    else puts("0");

    return 0;
}